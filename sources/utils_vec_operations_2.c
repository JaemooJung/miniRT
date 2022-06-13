/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:43:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/13 12:55:04 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include <math.h>

double	vlen_square(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vlen(t_vec3 vec)
{
	return (sqrt(vlen_square(vec)));
}

double	vdot(t_vec3 vec, t_vec3 vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec3	vcross(t_vec3 vec, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

t_vec3	vunit(t_vec3 vec)
{
	double	len;

	len = vlen(vec);
	if (len == 0)
		error("vunit: divided by zero");
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
