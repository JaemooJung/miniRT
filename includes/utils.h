/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:01:06 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/13 16:49:59 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

int	encode_color(t_color3 color);

t_color3	color(double r, double g, double b);
t_point3	point(double x, double y, double z);
t_vec3		vector(double x, double y, double z);

t_vec3		vplus(t_vec3 a, t_vec3 b);
t_vec3		vminus(t_vec3 a, t_vec3 b);
t_vec3		vmult_s(t_vec3 a, double t);
t_vec3		vmult_v(t_vec3 a, t_vec3 b);
t_vec3		vdiv(t_vec3 vec, double t);
double		vlen_square(t_vec3 vec);
double		vlen(t_vec3 vec);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);

#endif
