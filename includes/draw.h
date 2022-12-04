/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:47:49 by vfries            #+#    #+#             */
/*   Updated: 2022/12/04 01:57:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "points.h"
# include "ft_linked_list.h"

void	draw_fdf(t_fdf *fdf);
//void	draw_line(t_img *img, t_2d_point_i start, t_2d_point_i end);
void	get_clipped_line(t_proj_m *proj, t_list **lines_to_draw,
			t_vector_d start, t_vector_d end);

#endif
