/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clipped_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/02 01:37:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "fdf.h"
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

static void	add_line_to_draw(t_list **lines_to_draw,
			t_vector_d start, t_vector_d end)
{
	t_vector_d	*ret;

	ret = malloc(sizeof(t_vector_d) * 2);
	if (ret == NULL)
		return ;
	ret[0] = vector_divide(&start, start.w);
	ret[0].x = (ret[0].x + 1.0) * WINDOW_X / 2;
	ret[0].y = (ret[0].y + 1.0) * WINDOW_Y / 2;
	ret[1] = vector_divide(&end, end.w);
	ret[1].x = (ret[1].x + 1.0) * WINDOW_X / 2;
	ret[1].y = (ret[1].y + 1.0) * WINDOW_Y / 2;
	ft_lstadd_front(lines_to_draw, ft_lstnew(ret));
}

//	If vector.w is below z_near, it means the vector is behind the screen
//	the vector need to be cliped at the position it would have at the
//	screen edge
void	get_clipped_line(t_proj_m *proj, t_list **lines_to_draw,
		t_vector_d start, t_vector_d end)
{
	if (start.w < proj->z_near && end.w < proj->z_near)
		return ;
	if (end.w < proj->z_near)
		end = get_fixed_vector(proj, start, end);
	else if (start.w < proj->z_near)
		start = get_fixed_vector(proj, end, start);
	return (add_line_to_draw(lines_to_draw, start, end));
}
