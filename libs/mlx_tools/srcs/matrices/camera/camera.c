/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:17:10 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 15:11:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "rotation_matrices.h"
#include "matrix_multiplication.h"
#include "camera.h"

void	init_camera(t_cam *cam)
{
	t_matrix_4	cam_m;

	cam->cam = create_vector(0, 0, 0, 1);
	cam->up = create_vector(0, 1, 0, 1);
	cam->target = create_vector(0, 0, 1, 1);
	cam->yaw = 0.0;
	cam->rot_m = get_rotation_y_matrix(cam->yaw);
	cam->look_dir = matrix_times_vector(&cam->rot_m, &cam->target);
	cam->target = vector_add(&cam->cam, &cam->look_dir);
	cam_m = get_point_at_matrix(&cam->cam, &cam->target, &cam->up);
	cam->view_m = get_look_at_matrix(&cam_m);
	cam->forward = vector_multiply(&cam->look_dir, CAM_SPEED);
}

void	update_camera(t_cam *cam)
{
	t_matrix_4	cam_m;

	cam->target = create_vector(0, 0, 1, 1);
	cam->rot_m = get_rotation_y_matrix(cam->yaw);
	cam->look_dir = matrix_times_vector(&cam->rot_m, &cam->target);
	cam->target = vector_add(&cam->cam, &cam->look_dir);
	cam_m = get_point_at_matrix(&cam->cam, &cam->target, &cam->up);
	cam->view_m = get_look_at_matrix(&cam_m);
}
