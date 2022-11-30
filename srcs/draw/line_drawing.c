/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:07:53 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 19:24:55 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_tools.h"
#include "fdf.h"
#include "points.h"

static void	draw_line_low_angle(t_img *img, t_2d_point_i start, t_2d_point_i end)
{
	double	current_y;
	double	coef;

	coef = (double)(end.y - start.y) / (double)(end.x - start.x);
	current_y = start.y;
	while (start.x < end.x)
	{
		put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.x++;
		current_y += coef;
		start.y = (int)(current_y + 0.5);
	}
}

static void	draw_line_high_angle(t_img *img, t_2d_point_i start, t_2d_point_i end)
{
	double	current_x;
	double	coef;

	coef = (double)(end.x - start.x) / (double)(end.y - start.y);
	current_x = start.x;
	while (start.y < end.y)
	{
		put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.y++;
		current_x += coef;
		start.x = (int)(current_x + 0.5);
	}
}

void	draw_line(t_img *img, t_2d_point_i start, t_2d_point_i end)
{
	double	coef;

	if (start.x > end.x)
		return (draw_line(img, end, start));
	coef = (double)(end.y - start.y) / (double)(end.x - start.x);
	if (coef > -0.5 && coef < 0.5)
		return (draw_line_low_angle(img, start, end));
	if (start.y > end.y)
		return (draw_line_high_angle(img, end, start));
	draw_line_high_angle(img, start, end);
}
