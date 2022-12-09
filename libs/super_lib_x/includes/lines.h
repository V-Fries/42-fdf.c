/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:28:30 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:23:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINES_H
# define LINES_H

# include "img.h"

typedef struct s_line_point
{
	int		x;
	int		y;
	int		color;
	double	depth;
}	t_line_point;

void			draw_line(t_line_point start, t_line_point end, t_img *img);
t_line_point	create_t_line_point(int x, int y, int color, double depth);

#endif
