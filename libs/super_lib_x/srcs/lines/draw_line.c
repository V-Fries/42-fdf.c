// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_line.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/03 19:37:46 by vfries            #+#    #+#             */
// /*   Updated: 2022/12/04 01:33:05 by vfries           ###   ########lyon.fr   */
// /*                                                                            */
// /* ************************************************************************** */

#include "lines.h"
#include "slx_utils.h"
#include "mlx_tools.h"

static int	get_color(t_line_point start, t_line_point end)
{
	(void)start;
	(void)end;
	return (0xFFFFFF);
}

static void	get_incr(t_line_point start, t_line_point end,
						int *x_incr, int *y_incr)
{
	if (start.x > end.x)
		*x_incr = -1;
	else
		*x_incr = 1;
	if (start.y > end.y)
		*y_incr = -1;
	else
		*y_incr = 1;
}

static void	draw_line_high_slope(t_line_point start, t_line_point end,
		t_img *img, int color)
{
	int	error;
	int	diff_x;
	int	diff_y;
	int	x_incr;
	int	y_incr;

	get_incr(start, end, &x_incr, &y_incr);
	error = slx_abs(end.x - start.x);
	diff_x = 2 * error;
	diff_y = 2 * slx_abs(end.y - start.y);
	while (start.y < end.y)
	{
		if (color)
			put_pixel_on_img(img, start.y, start.x, get_color(start, end));
		else
			put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.y += y_incr;
		error -= diff_x;
		if (error < 0)
		{
			start.x += x_incr;
			error += diff_y;
		}
	}
}

static void	draw_line_low_slope(t_line_point start, t_line_point end,
		t_img *img, int color)
{
	int	error;
	int	diff_x;
	int	diff_y;
	int	x_incr;
	int	y_incr;

	get_incr(start, end, &x_incr, &y_incr);
	error = slx_abs(end.x - start.x);
	diff_x = 2 * error;
	diff_y = 2 * slx_abs(end.y - start.y);
	while (start.x < end.x)
	{
		if (color)
			put_pixel_on_img(img, start.y, start.x, get_color(start, end));
		else
			put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.x += x_incr;
		error -= diff_y;
		if (error < 0)
		{
			start.y += y_incr;
			error += diff_x;
		}
	}
}

void	draw_line(t_line_point start, t_line_point end,
		t_img *img, int color)
{
	double	coef;

	if (start.x > end.x)
		return (draw_line(end, start, img, color));
	coef = (double)(end.y - start.y) / (double)(end.x - start.x);
	if (coef > -0.5 && coef < 0.5)
		return (draw_line_low_slope(start, end, img, color));
	if (start.y > end.y)
		return (draw_line_high_slope(end, start, img, color));
	draw_line_high_slope(start, end, img, color);
}
