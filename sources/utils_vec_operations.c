/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:22:57 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/06/13 10:50:41 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include "structures.h"

t_vec3	vplus(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3	vminus(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3	vmult_s(t_vec3 a, double t)
{
	a.x *= t;
	a.y *= t;
	a.z *= t;
	return (a);
}

t_vec3	vmult_v(t_vec3 a, t_vec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vec3	vdiv(t_vec3 vec, double t)
{
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
