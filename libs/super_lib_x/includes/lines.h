/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:28:30 by vfries            #+#    #+#             */
/*   Updated: 2022/12/04 04:26:29 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINES_H
# define LINES_H

# include "mlx_tools.h"

typedef struct s_line_point
{
	int	x;
	int	y;
	int	color;
}	t_line_point;

void	draw_line(t_line_point start, t_line_point end, t_img *img);

#endif
