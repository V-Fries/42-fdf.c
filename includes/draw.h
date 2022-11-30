/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:47:49 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 19:25:04 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "points.h"

void	draw_fdf(t_fdf *fdf);
void	draw_line(t_img *img, t_2d_point_i start, t_2d_point_i end);

#endif
