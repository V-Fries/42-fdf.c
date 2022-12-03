/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:23:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/03 04:51:41 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "points.h"
#include "draw.h"
#include <stdlib.h>

#define BACK_GROUND_COLOR 0x000000

static t_2d_point_i	get_2d_point_from_vector(t_vector_d vec)
{
	t_2d_point_i	new;

	new.x = vec.x + 0.5;
	new.y = vec.y + 0.5;
	return (new);
}

static void	draw_lines(t_fdf *fdf, t_list *vectors)
{
	t_list	*free_me;

	while (vectors)
	{
		if (vectors->content == NULL)
		{
			vectors = vectors->next;
			continue ;
		}
		draw_line(&fdf->img,
			get_2d_point_from_vector(((t_vector_d *)(vectors->content))[0]),
			get_2d_point_from_vector(((t_vector_d *)(vectors->content))[1]));
		free(vectors->content);
		free_me = vectors;
		vectors = vectors->next;
		free(free_me);
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
			fdf->map.m[y][x] = matrix_times_vector(&fdf->mats.world,
					&fdf->map.o[y][x]);
			fdf->map.m[y][x] =  matrix_times_vector(&fdf->mats.proj.m,
					&fdf->map.m[y][x]);
		}
	}
}

static t_list	*get_lines(t_fdf *fdf)
{
	int		y;
	int		x;
	t_list	*lines_to_draw;

	lines_to_draw = NULL;
	y = -1;
	while (++y < fdf->map.y_size)
	{
		x = -1;
		while (++x < fdf->map.x_size)
		{
			if (x + 1 < 19)
				get_clipped_line(&fdf->mats.proj, &lines_to_draw,
					fdf->map.m[y][x], fdf->map.m[y][x + 1]);
			if (y + 1 < 11)
				get_clipped_line(&fdf->mats.proj, &lines_to_draw,
					fdf->map.m[y][x], fdf->map.m[y + 1][x]);
		}
	}
	return (lines_to_draw);
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
	draw_lines(fdf, get_lines(fdf));
	put_img(&fdf->img, &fdf->win);
}
