/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:13 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 21:14:09 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSPECTIVE_PROJECTION_H
# define PERSPECTIVE_PROJECTION_H

# include "points.h"

t_2d_point_i	perspective_projection(t_3d_point_i a, t_3d_point_i c, t_3d_point_i o,
	t_3d_point_i e);

#endif
