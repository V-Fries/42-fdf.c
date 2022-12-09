/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clipped_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:18:11 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lines.h"

// v1 is assumed to be on the screen !
static t_vector_d	get_fixed_vector(t_proj_m *proj,
					t_vector_d v1, t_vector_d v2)
{
	t_vector_d	new;
	double		n;

	n = (v1.w - proj->z_near) / (v1.w - v2.w);
	new.x = (n * v1.x) + ((1 - n) * v2.x);
	new.y = (n * v1.y) + ((1 - n) * v2.y);
	new.z = (n * v1.z) + ((1 - n) * v2.z);
	new.w = proj->z_near;
	return (new);
}

static double	get_depth(double depth_1, double depth_2)
{
	if (depth_1 > depth_2)
		return (depth_1);
	return (depth_2);
}

static t_vector_d	adjust_vector_to_screen(t_fdf *fdf, t_vector_d vector)
{
	if (fdf->mats.proj.type == PROJ_PERSEPECTIVE)
	{
		vector = vector_divide(&vector, vector.w);
		vector.x = (vector.x + 1.0) * (double)WINDOW_X / 2.0 + 0.5;
		vector.y = (vector.y + 1.0) * (double)WINDOW_Y / 2.0 + 0.5;
	}
	else
	{
		vector.x = (vector.x + 1.0) + (double)WINDOW_X / 2.0 + 0.5;
		vector.y = (vector.y + 1.0) + (double)WINDOW_Y / 2.0 + 0.5;
	}
	return (vector);
}

static void	draw_line_with_fixed_vectors(t_vector_d start, t_vector_d end,
										t_fdf *fdf, int color)
{
	t_line_point	start_line;
	t_line_point	end_line;

	start = adjust_vector_to_screen(fdf, start);
	end = adjust_vector_to_screen(fdf, end);
	if (fdf->view_mode == VIEW_LINES)
	{
		start_line = create_t_line_point(start.x, start.y, color,
				get_depth(start.z, end.z));
		end_line = create_t_line_point(end.x, end.y, color,
				get_depth(start.z, end.z));
		draw_line(start_line, end_line, &fdf->img);
		return ;
	}
	if (start.y >= 0 && start.y < fdf->img.y_size
		&& start.x >= 0 && start.x < fdf->img.x_size)
		put_pixel_on_img(&fdf->img,
			create_t_pixel(start.x, start.y, color, get_depth(start.z, end.z)));
	if (end.y >= 0 && end.y < fdf->img.y_size
		&& end.x >= 0 && end.x < fdf->img.x_size)
		put_pixel_on_img(&fdf->img,
			create_t_pixel(end.x, end.y, color, get_depth(start.z, end.z)));
}

//	If vector.w is below z_near, it means the vector is behind the screen
//	the vector need to be cliped at the position it would have at the
//	screen edge
void	draw_clipped_line(t_vector_d start, t_vector_d end, t_fdf *fdf,
							int color)
{
	if (start.w < fdf->mats.proj.z_near && end.w < fdf->mats.proj.z_near)
		return ;
	if (end.w < fdf->mats.proj.z_near)
		end = get_fixed_vector(&fdf->mats.proj, start, end);
	else if (start.w < fdf->mats.proj.z_near)
		start = get_fixed_vector(&fdf->mats.proj, end, start);
	draw_line_with_fixed_vectors(start, end, fdf, color);
}
