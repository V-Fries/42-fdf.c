/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_clip_vectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/02 01:04:55 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "fdf.h"
#include <stdlib.h>

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

static void	add_line_to_draw(t_list **vectors, t_vector_d start, t_vector_d end)
{
	t_vector_d	*ret;

	ret = malloc(sizeof(t_vector_d) * 2);
	if (ret == NULL)
		return ;
	// start.x = (start.x / start.w) * 1400.0;
	// start.y = (start.y / start.w) * 1400.0;
	// end.x = (end.x / end.w) * 1400.0;
	// end.y = (end.y / end.w) * 1400.0;
	// ret[0] = start;
	// ret[1] = end;
	// if (start.w != 0.1)
	// {
	ret[0] = vector_divide(&start, start.w);
	ret[0].x = (ret[0].x + 1.0) * WINDOW_X / 2;
	ret[0].y = (ret[0].y + 1.0) * WINDOW_Y / 2;
	// }
	// else
	// 	ret[0] = start;
	// if (end.w != 0.1)
	// {
		ret[1] = vector_divide(&end, end.w);
		ret[1].x = (ret[1].x + 1.0) * WINDOW_X / 2;
		ret[1].y = (ret[1].y + 1.0) * WINDOW_Y / 2;
	// }
	// else
	// 	ret[1] = end;
	ft_lstadd_front(vectors, ft_lstnew(ret));
}


#include "ft_io.h"
void	get_no_clip_vectors(t_proj_m *proj, t_list **vectors,
		t_vector_d start, t_vector_d end)
{
	if (start.w < proj->z_near && end.w < proj->z_near)
	{
		ft_putstr("WTF is that!");
		return ;
	}
	if (start.w < proj->z_near)
	{
		ft_putstr("WTF is that!");
		start = get_fixed_vector(proj, end, start);
		return (add_line_to_draw(vectors, start, end));
	}
	if (end.w < proj->z_near)
	{
		ft_putstr("WTF is that!");
		end = get_fixed_vector(proj, start, end);
		return (add_line_to_draw(vectors, start, end));
	}
	// ft_putstr("Cool vector!");
	return (add_line_to_draw(vectors, start, end));
}
