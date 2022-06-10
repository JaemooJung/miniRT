/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:04:00 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/10 17:47:06 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"

int	key_hook(int keycode, t_mlx_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_image(info->mlx_ptr, info->img_ptr);
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		exit(0);
	}
	return (0);
}

int	terminate(t_mlx_info *info)
{
	t_mlx_info	*c_info;

	c_info = (t_mlx_info *)info;
	mlx_destroy_image(c_info->mlx_ptr, c_info->img_ptr);
	mlx_destroy_window(c_info->mlx_ptr, c_info->win_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
	t_mlx_info	info;

	init_mlx(&info);
	draw_scene(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_key_hook(info.win_ptr, key_hook, &info);
	mlx_hook(info.win_ptr, 17, 0, terminate, &info);
	mlx_loop(info.mlx_ptr);
}
