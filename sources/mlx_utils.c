/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:40:56 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/10 17:41:10 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	init_mlx(t_mlx_info *info)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		error("mlx init failed");
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIN_W, WIN_H, "miniRT");
	if (info->win_ptr == NULL)
		error("window init failed");
	info->img_ptr = mlx_new_image(info->mlx_ptr, WIN_W, WIN_H);
	if (info->img_ptr == NULL)
		error("image init failed");
	info->addr = mlx_get_data_addr(info->img_ptr, &info->bpp,
			&info->line_len, &info->endian);
	if (info->addr == NULL)
		error("failed to get img addr");
}
