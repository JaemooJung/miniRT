/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:08:01 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/11 19:20:42 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

int	encode_color(t_color3 color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.x * 255.999);
	g = (int)(color.y * 255.999);
	b = (int)(color.z * 255.999);
	return ((r << 16) | (g << 8) | b);
}

t_color3	color(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

t_point3	point(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vec3	vector(double x, double y, double z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}