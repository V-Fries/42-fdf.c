/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:13 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 11:47:21 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSPECTIVE_PROJECTION_H
# define PERSPECTIVE_PROJECTION_H

t_2d_point	perspective_projection(t_3d_point a, t_3d_point c, t_3d_point o,
	t_3d_point e);

#endif
