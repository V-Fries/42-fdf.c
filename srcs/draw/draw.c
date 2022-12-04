/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:23:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/04 05:07:43 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

#define BACK_GROUND_COLOR 0x000000

static void	fill_m_v_map(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->map.y_size)
	{
		x = -1;
		while (++x < fdf->map.x_size)
		{
			fdf->map.m[y][x] = matrix_times_vector(&fdf->mats.world,
					&fdf->map.o[y][x]);
			fdf->map.m[y][x] =  matrix_times_vector(&fdf->mats.proj.m,
					&fdf->map.m[y][x]);
		}
	}
}

static void	draw_lines(t_fdf *fdf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < fdf->map.y_size)
	{
		x = -1;
		while (++x < fdf->map.x_size)
		{
			if (x + 1 < fdf->map.x_size)
				draw_clipped_line(&fdf->mats.proj,
					fdf->map.m[y][x], fdf->map.m[y][x + 1], &fdf->img);
			if (y + 1 < fdf->map.y_size)
				draw_clipped_line(&fdf->mats.proj,
					fdf->map.m[y][x], fdf->map.m[y + 1][x], &fdf->img);
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
			put_pixel_on_img(&fdf->img, y, x, BACK_GROUND_COLOR);
	}
	fill_m_v_map(fdf);
	draw_lines(fdf);
	put_img(&fdf->img, &fdf->win);
}
