/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:08:01 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/10 17:41:21 by jaemjung         ###   ########.fr       */
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
