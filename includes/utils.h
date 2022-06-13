/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:01:06 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/11 19:32:03 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

int	encode_color(t_color3 color);

t_color3	color(double r, double g, double b);
t_point3	point(double x, double y, double z);
t_vec3		vector(double x, double y, double z);

t_vec3	vplus(t_vec3 a, t_vec3 b);
t_vec3	vminus(t_vec3 a, t_vec3 b);
t_vec3	vmult_s(t_vec3 a, double t);
t_vec3	vmult_v(t_vec3 a, t_vec3 b);
t_vec3	vdiv(t_vec3 vec, double t);

#endif
