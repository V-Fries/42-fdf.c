/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:47:49 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 23:32:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_H
# define LINE_DRAWING_H

# include "points.h"

void	draw_line_low_angle(t_img *img, t_2d_point_i start, t_2d_point_i end);
void	draw_line_high_angle(t_img *img, t_2d_point_i start, t_2d_point_i end);
void	draw_line(t_img *img, t_2d_point_i start, t_2d_point_i end);

#endif
