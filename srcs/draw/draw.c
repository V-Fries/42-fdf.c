/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:23:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 17:18:56 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "colors.h"

static void	fill_map_m(t_fdf *fdf)
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
					&fdf->map.a[y][x]);
			fdf->map.m[y][x] = matrix_times_vector(&fdf->mats.proj.m,
					&fdf->map.m[y][x]);
		}
	}
}

static int	get_color(t_fdf *fdf, double altitude_1, double altitude_2)
{
	int	color;

	if (fdf->colors == false)
		return (COLOR_WHITE);
	if (altitude_1 < altitude_2)
		color = altitude_1 - 0.5;
	else
		color = altitude_2 - 0.5;
	if (color < -120)
		color = COLOR_SNOW_WHITE;
	else if (color < -50)
		color = COLOR_ROCK;
	else if (color < -6)
		color = COLOR_GRASS_GREEN;
	else if (color < -2)
		color = COLOR_SAND;
	else
		color = COLOR_SEA_BLUE + 32;
	((unsigned char *)&color)[3] = 0;
	return (color);
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
				draw_clipped_line(fdf->map.m[y][x], fdf->map.m[y][x + 1],
					fdf, get_color(fdf,
						fdf->map.o[y][x].z, fdf->map.o[y][x + 1].z));
			if (y + 1 < fdf->map.y_size)
				draw_clipped_line(fdf->map.m[y][x], fdf->map.m[y + 1][x],
					fdf, get_color(fdf,
						fdf->map.o[y][x].z, fdf->map.o[y + 1][x].z));
		}
	}
}

void	draw_fdf(t_fdf *fdf)
{
	reset_img(&fdf->img, 0x000000);
	fill_map_m(fdf);
	draw_lines(fdf);
	put_img(&fdf->img, &fdf->win);
}
