/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:54:41 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 00:54:40 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lines.h"
#include "mlx_tools.h"
#include <stdbool.h>
#include <stdint.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

static uint8_t	get_region(t_line_point point, t_img *img)
{
	uint8_t	region;

	region = INSIDE;
	if (point.y >= img->y_size)
		region |= TOP;
	else if (point.y < 0)
		region |= BOTTOM;
	if (point.x >= img->x_size)
		region |= RIGHT;
	else if (point.x < 0)
		region |= LEFT;
	return (region);
}

static t_line_point	clip_line(t_line_point p1, t_line_point p2,
					uint8_t tested_region, t_img *img)
{
	if (tested_region & TOP)
		return (create_t_line_point(
				p1.x + (p2.x - p1.x) * (img->y_size - 1 - p1.y) / (p2.y - p1.y),
				img->y_size - 1,
				0xFFFFFF));
	if (tested_region & BOTTOM)
		return (create_t_line_point(
				p1.x + (p2.x - p1.x) * (.0 - p1.y) / (p2.y - p1.y),
				0.0,
				0xFFFFFF));
	if (tested_region & RIGHT)
		return (create_t_line_point(
				img->x_size - 1,
				p1.y + (p2.y - p1.y) * (img->x_size - 1 - p1.x) / (p2.x - p1.x),
				0xFFFFFF));
	return (create_t_line_point(
			0.0,
			p1.y + (p2.y - p1.y) * (.0 - p1.x) / (p2.x - p1.x),
			0xFFFFFF));
}

// https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
bool	line_clipping(t_line_point *start, t_line_point *end, t_img *img)
{
	uint8_t	start_region;
	uint8_t	end_region;

	while (true)
	{
		start_region = get_region(*start, img);
		end_region = get_region(*end, img);
		if (!(start_region | end_region))
			return (true);
		else if (start_region & end_region)
			return (false);
		else if (start_region > end_region)
			*start = clip_line(*start, *end, start_region, img);
		else
			*end = clip_line(*start, *end, end_region, img);
	}
}
