/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clipped_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/04 05:06:37 by vfries           ###   ########lyon.fr   */
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
										t_img *img)
{
	t_line_point	start_line;
	t_line_point	end_line;

	start = vector_divide(&start, start.w);
	start.x = (start.x + 1.0) * WINDOW_X / 2;
	start.y = (start.y + 1.0) * WINDOW_Y / 2;
	end = vector_divide(&end, end.w);
	end.x = (end.x + 1.0) * WINDOW_X / 2;
	end.y = (end.y + 1.0) * WINDOW_Y / 2;
	start_line.x = start.x + 0.5;
	start_line.y = start.y + 0.5;
	start_line.color = 0xFFFFFF;
	end_line.x = end.x + 0.5;
	end_line.y = end.y + 0.5;
	end_line.color = 0xFFFFFF;
	draw_line(start_line, end_line, img);
}

//	If vector.w is below z_near, it means the vector is behind the screen
//	the vector need to be cliped at the position it would have at the
//	screen edge
void	draw_clipped_line(t_proj_m *proj,
		t_vector_d start, t_vector_d end, t_img *img)
{
	if (start.w < proj->z_near && end.w < proj->z_near)
		return ;
	if (end.w < proj->z_near)
		end = get_fixed_vector(proj, start, end);
	else if (start.w < proj->z_near)
		start = get_fixed_vector(proj, end, start);
	draw_line_with_fixed_vectors(start, end, img);
}
