/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:23:28 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 22:57:14 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "points.h"
#include "vector.h"
#include "draw.h"

static t_2d_point_i	get_2d_point_from_vector(t_vector_d vec)
{
	t_2d_point_i	new;

	new.x = vec.x + 0.5;
	new.y = vec.y + 0.5;
	return (new);
}

static void	draw_lines(t_fdf *fdf)
{
	t_2d_point_i	start;
	t_2d_point_i	end;
	int				y;
	int				x;

	y = -1;
	while (++y < 11)
	{
		x = -1;
		while (++x < 19)
		{
			if (x + 1 < 19)
			{
				start = get_2d_point_from_vector(fdf->map.m_v_map[y][x]);
				end = get_2d_point_from_vector(fdf->map.m_v_map[y][x + 1]);
				draw_line(&fdf->img, start, end);
			}
			if (y + 1 < 11)
			{
				start = get_2d_point_from_vector(fdf->map.m_v_map[y][x]);
				end = get_2d_point_from_vector(fdf->map.m_v_map[y + 1][x]);
				draw_line(&fdf->img, start, end);
			}
		}
	}
}

static void	fill_m_v_map(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 11)
	{
		x = -1;
		while (++x < 19)
		{
			fdf->map.m_v_map[y][x] = matrix_times_vector(&fdf->mats.world,
					&fdf->map.o_v_map[y][x]);
			fdf->map.m_v_map[y][x] = matrix_times_vector(&fdf->mats.proj.m,
					&fdf->map.m_v_map[y][x]);
			fdf->map.m_v_map[y][x] = vector_divide(&fdf->map.m_v_map[y][x],
					fdf->map.m_v_map[y][x].w);
			fdf->map.m_v_map[y][x].x += 1.0;
			fdf->map.m_v_map[y][x].y += 1.0;
			fdf->map.m_v_map[y][x].x *= 0.5 * (double)WINDOW_X;
			fdf->map.m_v_map[y][x].y *= 0.5 * (double)WINDOW_Y;
		}
	}
}

void	draw_fdf(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->img.y_size)
	{
		x = -1;
		while (++x < fdf->img.x_size)
			put_pixel_on_img(&fdf->img, y, x, 0x000000);
	}
	fill_m_v_map(fdf);
	draw_lines(fdf);
	put_img(&fdf->img, &fdf->win);
}
