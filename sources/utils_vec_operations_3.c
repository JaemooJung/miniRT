/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec_operations_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:48:39 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/13 16:49:11 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}