/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clipped_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/05 23:54:32 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lines.h"
#include <stdlib.h>

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

static void	draw_line_with_fixed_vectors(t_vector_d start, t_vector_d end,
										t_fdf *fdf)
{
	t_line_point	start_line;
	t_line_point	end_line;

	start = vector_divide(&start, start.w);
	start.x = (start.x + 1.0) * WINDOW_X / 2 + 0.5;
	start.y = (start.y + 1.0) * WINDOW_Y / 2 + 0.5;
	end = vector_divide(&end, end.w);
	end.x = (end.x + 1.0) * WINDOW_X / 2 + 0.5;
	end.y = (end.y + 1.0) * WINDOW_Y / 2 + 0.5;
	if (fdf->view_mode == VIEW_POINTS)
	{
		if (start.y >= 0 && start.y < fdf->img.y_size
			&& start.x >= 0 && start.x < fdf->img.x_size)
			put_pixel_on_img(&fdf->img, start.y, start.x, 0xFFFFFF);
		if (end.y >= 0 && end.y < fdf->img.y_size
			&& end.x >= 0 && end.x < fdf->img.x_size)
			put_pixel_on_img(&fdf->img, end.y, end.x, 0xFFFFFF);
		return ;
	}
	start_line = create_t_line_point(start.x, start.y, 0xFFFFFF);
	end_line = create_t_line_point(end.x, end.y, 0xFFFFFF);
	draw_line(start_line, end_line, &fdf->img);
}

//	If vector.w is below z_near, it means the vector is behind the screen
//	the vector need to be cliped at the position it would have at the
//	screen edge
void	draw_clipped_line(t_proj_m *proj,
		t_vector_d start, t_vector_d end, t_fdf *fdf)
{
	if (start.w < proj->z_near && end.w < proj->z_near)
		return ;
	if (end.w < proj->z_near)
		end = get_fixed_vector(proj, start, end);
	else if (start.w < proj->z_near)
		start = get_fixed_vector(proj, end, start);
	draw_line_with_fixed_vectors(start, end, fdf);
}
