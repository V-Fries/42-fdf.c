/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_line_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:07:45 by vfries            #+#    #+#             */
/*   Updated: 2022/12/05 23:09:03 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lines.h"

t_line_point	create_t_line_point(int x, int y, int color)
{
	t_line_point	new;

	new.x = x;
	new.y = y;
	new.color = color;
	return (new);
}
