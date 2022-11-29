/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:17:10 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:37:49 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	init_camera(t_cam *cam)
{
	cam->cam = create_vector(0, 0, 0, 1);
	cam->look_dir = create_vector(0, 0, 1, 1);
	cam->look_dir = create_vector(0, 0, 1, 1);
	cam->up = create_vector(0, 1, 0, 1);
	cam->target = vector_add(&cam->cam, &cam->look_dir);
	cam->cam_mat = get_point_at_matrix(&cam->cam, &cam->target, &cam->up);
	cam->view_mat = get_look_at_matrix(&cam->cam_mat);
}
