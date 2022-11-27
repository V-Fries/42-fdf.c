/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:47:49 by vfries            #+#    #+#             */
/*   Updated: 2022/11/27 20:11:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_H
# define LINE_DRAWING_H

void	draw_line_low_angle(t_img *img, t_2d_point start, t_2d_point end);
void	draw_line_high_angle(t_img *img, t_2d_point start, t_2d_point end);
void	draw_line(t_img *img, t_2d_point start, t_2d_point end);

#endif
