/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemung <jaemjung@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:40:39 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/27 23:44:58 by jaemung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_phong_light	pl;

	pl.light_dir = vunit(vminus(light->origin, scene->rec.p));
	pl.light_len = vlength(pl.light_dir);
	pl.light_ray = ray(vplus(scene->rec.p, vmult(scene->rec.normal, 1e-3)),
			pl.light_dir);
	if (in_shadow(scene->world, pl.light_ray, pl.light_len))
		return (color3(0.0, 0.0, 0.0));
	pl.kd = fmax(vdot(scene->rec.normal, pl.light_dir), 0.0);
	pl.diffuse = vmult(light->light_color, pl.kd);
	pl.view_dir = vunit(vmult(scene->ray.dir, -1));
	pl.reflect_dir = reflect(vmult(pl.light_dir, -1), scene->rec.normal);
	pl.ksn = 64;
	pl.ks = 0.3;
	pl.spec = pow(fmax(vdot(pl.view_dir, pl.reflect_dir), 0.0), pl.ksn);
	pl.specular = vmult(vmult(light->light_color, pl.ks), pl.spec);
	pl.brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(scene->ambient, pl.diffuse), pl.specular),
			pl.brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*light;

	light_color = color3(0, 0, 0);
	light = scene->light;
	if (light->type == LIGHT_POINT)
		light_color = vplus(light_color,
				point_light_get(scene, light->element));
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
