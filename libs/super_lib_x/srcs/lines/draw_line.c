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

// static int	get_color(t_line_point start, t_line_point end)
// {
// 	(void)start;
// 	(void)end;
// 	return (0xFFFFFF);
// }

typedef struct s_bresenham
{
	int	error_x;
	int	error_y;
	int	diff_x;
	int	diff_y;
	int	starting_error_x;
	int	starting_error_y;
	int	x_incr;
	int	y_incr;
}	t_bresenham;

static void	draw_low_slope(t_line_point start,
			t_bresenham params, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_x)
	{
		put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.x += params.x_incr;
		params.error_x -= params.diff_y;
		if (params.error_x < 0)
		{
			start.y += params.y_incr;
			params.error_x += params.diff_x;
		}
	}
}

static void	draw_high_slope(t_line_point start,
			t_bresenham params, t_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_y)
	{
		put_pixel_on_img(img, start.y, start.x, 0xFFFFFF);
		start.y += params.y_incr;
		params.error_y -= params.diff_x;
		if (params.error_y < 0)
		{
			start.x += params.x_incr;
			params.error_y += params.diff_y;
		}
	}
}

static char	fix_straight_line_points(t_line_point *start, t_line_point *end,
								t_img *img)
{
	if (start->x == end->x)
	{
		if (end->x < 0 || end->x >= img->x_size)
			return (-1);
		if (end->y < 0)
			return (-1);
		if (end->y >= img->y_size)
			end->y = img->y_size - 1;
		if (start->y < 0)
			start->y = 0;
	}
	else
	{
		if (end->y < 0 || end->y >= img->y_size)
			return (-1);
		if (end->x < 0)
			return (-1);
		if (end->x >= img->x_size)
			end->x = img->x_size - 1;
		if (start->x < 0)
			start->x = 0;
	}
	return (0);
}

static void	draw_straight_line(t_line_point start, t_line_point end, t_img *img)
{
	if (start.x == end.x)
	{
		if (start.y > end.y)
			return (draw_straight_line(end, start, img));
		if (fix_straight_line_points(&start, &end, img) == -1)
			return ;
		while (start.y <= end.y)
			put_pixel_on_img(img, start.y++, start.x, 0xFFFFFF);
	}
	else
	{
		if (start.x > end.x)
			return (draw_straight_line(end, start, img));
		if (fix_straight_line_points(&start, &end, img) == -1)
			return ;
		while (start.x <= end.x)
			put_pixel_on_img(img, start.y, start.x++, 0xFFFFFF);
	}
}

void	draw_line(t_line_point start, t_line_point end, t_img *img)
{
	t_bresenham	params;

	if ((start.x < 0 && end.x < 0)
		|| (start.x >= img->x_size && end.x >= img->x_size)
		|| (start.y < 0 && end.y < 0)
		|| (start.y >= img->y_size && end.y >= img->y_size))
		return ;
	if (start.x == end.x || start.y == end.y)
		return (draw_straight_line(start, end, img));
	params.error_x = slx_abs(end.x - start.x);
	params.error_y = slx_abs(end.y - start.y);
	params.diff_x = 2 * params.error_x;
	params.diff_y = 2 * params.error_y;
	params.starting_error_x = params.error_x;
	params.starting_error_y = params.error_y;
	params.x_incr = 1;
	if (start.x > end.x)
		params.x_incr = -1;
	params.y_incr = 1;
	if (start.y > end.y)
		params.y_incr = -1;
	if (params.starting_error_x > params.starting_error_y)
		draw_low_slope(start, params, img);
	else if (params.starting_error_x < params.starting_error_y)
		draw_high_slope(start, params, img);
}
