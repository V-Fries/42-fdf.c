/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:47:00 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:27:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrices.h"
# include "vector.h"

typedef struct s_cam
{
	t_vector_d	cam;
	t_vector_d	look_dir;
	t_vector_d	up;
	t_vector_d	target;
	t_matrix_4	cam_mat;
	t_matrix_4	view_mat;
}	t_cam;


void		init_camera(t_cam *cam);
t_matrix_4	get_point_at_matrix(t_vector_d *pos, t_vector_d *target,
				t_vector_d *up);
t_matrix_4	get_look_at_matrix(t_matrix_4 *point_at_m);

#endif