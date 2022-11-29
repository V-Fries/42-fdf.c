/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:13 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 01:53:42 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSPECTIVE_PROJECTION_H
# define PERSPECTIVE_PROJECTION_H

# include "points.h"
# include "vector.h"

t_2d_point_i	perspective_projection(t_vector_i a, t_vector_i c, t_vector_i o,
	t_vector_i e);

#endif
