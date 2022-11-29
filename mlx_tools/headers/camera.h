/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:47:00 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 07:48:55 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrices.h"
# include "vector.h"

t_matrix_4 get_point_at_matrix(t_vector_d *pos, t_vector_d *target,
		t_vector_d *up);

#endif