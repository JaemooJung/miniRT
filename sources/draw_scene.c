/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:54:09 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/10 17:40:12 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_utils.h"
#include "utils.h"
#include "scene.h"

t_color3	get_pixel_color(void)
{
	t_color3	color;

	color.x = 1;
	color.y = 1;
	color.z = 1;
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
	int			i;
	int			j;
	t_color3	pixel_color;

	i = -1;
	while (++i < WIN_H)
	{
		j = -1;
		while (++j < WIN_W)
		{
			pixel_color = get_pixel_color();
			// draw_pixel(info, i, j, encode_color(pixel_color));
			mlx_pixel_put(info->mlx_ptr, info->win_ptr, j, i,
				encode_color(pixel_color));
		}
	}
}
