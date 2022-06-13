/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:04:00 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/11 19:18:39 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"

int	terminate(t_mlx_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->img_ptr);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx_info *info)
{
	if (keycode == 53)
		terminate(info);
	return (0);
}

int	main(void)
{
	t_mlx_info	info;

	init_mlx(&info);
	// parse_description();
	draw_scene(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_key_hook(info.win_ptr, key_hook, &info);
	mlx_hook(info.win_ptr, 17, 0, terminate, &info);
	mlx_loop(info.mlx_ptr);
}
