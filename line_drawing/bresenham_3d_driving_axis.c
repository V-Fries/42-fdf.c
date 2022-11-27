/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_3d_driving_axis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:40:24 by vfries            #+#    #+#             */
/*   Updated: 2022/11/27 14:43:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "bresenham_3d.h"
#include "utils.h"
#include <stdlib.h>

char	add_elem_to_list(t_list **last_elem, t_3d_point content_data)
{
	t_3d_point	*content;
	t_list		*new;

	content = malloc(sizeof(t_3d_point));
	if (content == NULL)
		return (-1);
	*content = content_data;
	new = ft_lstnew(content);
	if (new == NULL)
		return (free(content), -1);
	if (*last_elem)
		(*last_elem)->next = new;
	(*last_elem) = new;
	return (0);
}

char	bresenham_3d_driving_axis_x(t_3d_point start, t_3d_point end,
			t_bresenham_3d bresenham, t_list *last_elem)
{
	int	p1;
	int	p2;

	p1 = 2 * bresenham.abs_diff.y - bresenham.abs_diff.x;
	p2 = 2 * bresenham.abs_diff.z - bresenham.abs_diff.x;
	while (start.x != end.x)
	{
		start.x += bresenham.increment.x;
		if (p1 >= 0)
		{
			start.y += bresenham.increment.y;
			p1 -= 2 * bresenham.abs_diff.x;
		}
		if (p2 >= 0)
		{
			start.z += bresenham.increment.z;
			p2 -= 2 * bresenham.abs_diff.x;
		}
		p1 += 2 * bresenham.abs_diff.y;
		p2 += 2 * bresenham.abs_diff.z;
		if (add_elem_to_list(&last_elem, start) == -1)
			return (-1);
	}
	return (0);
}

char	bresenham_3d_driving_axis_y(t_3d_point start, t_3d_point end,
			t_bresenham_3d bresenham, t_list *last_elem)
{
	int	p1;
	int	p2;

	p1 = 2 * bresenham.abs_diff.x - bresenham.abs_diff.y;
	p2 = 2 * bresenham.abs_diff.z - bresenham.abs_diff.y;
	while (start.y != end.y)
	{
		start.y += bresenham.increment.y;
		if (p1 >= 0)
		{
			start.x += bresenham.increment.x;
			p1 -= 2 * bresenham.abs_diff.y;
		}
		if (p2 >= 0)
		{
			start.z += bresenham.increment.z;
			p2 -= 2 * bresenham.abs_diff.y;
		}
		p1 += 2 * bresenham.abs_diff.x;
		p2 += 2 * bresenham.abs_diff.z;
		if (add_elem_to_list(&last_elem, start) == -1)
			return (-1);
	}
	return (0);
}

char	bresenham_3d_driving_axis_z(t_3d_point start, t_3d_point end,
			t_bresenham_3d bresenham, t_list *last_elem)
{
	int	p1;
	int	p2;

	p1 = 2 * bresenham.abs_diff.y - bresenham.abs_diff.z;
	p2 = 2 * bresenham.abs_diff.x - bresenham.abs_diff.z;
	while (start.z != end.z)
	{
		start.z += bresenham.increment.z;
		if (p1 >= 0)
		{
			start.y += bresenham.increment.y;
			p1 -= 2 * bresenham.abs_diff.z;
		}
		if (p2 >= 0)
		{
			start.x += bresenham.increment.x;
			p2 -= 2 * bresenham.abs_diff.z;
		}
		p1 += 2 * bresenham.abs_diff.y;
		p2 += 2 * bresenham.abs_diff.x;
		if (add_elem_to_list(&last_elem, start) == -1)
			return (-1);
	}
	return (0);
}
