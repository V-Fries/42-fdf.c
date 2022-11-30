/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:24:55 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 18:17:12 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_linked_list.h"

t_list	*bresenham_2d(t_2d_point start, t_2d_point end)
{
	int		d;
	int		i1;
	int		i2;
	int		dx;
	int		dy;
	char	angle_is_steep;

	dx = end.x - start.x;
	dy = end.y - start.y;




	i1 = dy * 2;
	i2 = (dy - dx) * 2;
	d = i1 - dx;

}
