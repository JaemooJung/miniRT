/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:54:09 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/13 16:51:17 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_utils.h"
#include "utils.h"
#include "scene.h"

t_color3	get_pixel_color(int x, int y)
{
	t_color3	color;

	color.x = (double)x / (WIN_W - 1);
	color.y = (double)y / (WIN_H - 1);
	color.z = 0.25;
	return (color);
}

void	draw_pixel(t_mlx_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_scene(t_mlx_info *info)
{
	int			x;
	int			y;
	int			u;
	int			v;
	t_color3	pixel_color;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			pixel_color = get_pixel_color(x, y);
			draw_pixel(info, x, y, encode_color(pixel_color));
		}
	}
}
