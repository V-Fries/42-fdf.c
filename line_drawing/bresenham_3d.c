/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:14:07 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 23:31:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "utils.h"
#include "points.h"
#include "bresenham_3d.h"
#include "ft_numbers.h"
#include <stdlib.h>

char	add_elem_to_list(t_list **last_elem, t_3d_point_i content_data);
char	bresenham_3d_driving_axis_x(t_3d_point_i start, t_3d_point_i end,
			t_bresenham_3d bresenham, t_list *last_elem);
char	bresenham_3d_driving_axis_y(t_3d_point_i start, t_3d_point_i end,
			t_bresenham_3d bresenham, t_list *last_elem);
char	bresenham_3d_driving_axis_z(t_3d_point_i start, t_3d_point_i end,
			t_bresenham_3d bresenham, t_list *last_elem);

static t_bresenham_3d	init_bresenham_3d(t_3d_point_i start, t_3d_point_i end)
{
	t_bresenham_3d	bresenham;

	bresenham.abs_diff.x = ft_abs(end.x - start.x);
	bresenham.abs_diff.y = ft_abs(end.y - start.y);
	bresenham.abs_diff.z = ft_abs(end.z - start.z);
	if (end.x > start.x)
		bresenham.increment.x = 1;
	else
		bresenham.increment.x = -1;
	if (end.y > start.y)
		bresenham.increment.y = 1;
	else
		bresenham.increment.y = -1;
	if (end.z > start.z)
		bresenham.increment.z = 1;
	else
		bresenham.increment.z = -1;
	return (bresenham);
}

// Bresenham's Algorithm
t_list	*bresenham_3d(t_3d_point_i start, t_3d_point_i end)
{
	t_list			*list_of_points;
	t_bresenham_3d	bresenham;

	list_of_points = NULL;
	if (add_elem_to_list(&list_of_points, start) == -1)
		return (NULL);
	bresenham = init_bresenham_3d(start, end);
	if (bresenham.abs_diff.x >= bresenham.abs_diff.y
		&& bresenham.abs_diff.x >= bresenham.abs_diff.z)
	{
		if (bresenham_3d_driving_axis_x(start, end, bresenham, list_of_points)
			== -1)
			return (ft_lstclear(&list_of_points, &free), NULL);
	}
	else if (bresenham.abs_diff.y >= bresenham.abs_diff.x
		&& bresenham.abs_diff.y >= bresenham.abs_diff.z)
	{
		if (bresenham_3d_driving_axis_y(start, end, bresenham, list_of_points)
			== -1)
			return (ft_lstclear(&list_of_points, &free), NULL);
	}
	else
		if (bresenham_3d_driving_axis_z(start, end, bresenham, list_of_points)
			== -1)
			return (ft_lstclear(&list_of_points, &free), NULL);
	return (list_of_points);
}


// #include <stdio.h>

// int	main(void)
// {
// 	t_3d_point_i	start = {-1, 1, 1};
// 	t_3d_point_i	end = {5, 3, -1};
// 	t_list *res = bresenham_3d(start, end);

// 	printf("[");
// 	for (t_list *current = res; current; current = current->next)
// 	{
// 		printf("(%d, %d, %d), ", ((t_3d_point_i *)(current->content))->x,
//((t_3d_point_i *)(current->content))->y, ((t_3d_point_i *)(current->content))->z);
// 	}
// 	printf("]\n");
// 	ft_lstclear(&res, &free);
// }
