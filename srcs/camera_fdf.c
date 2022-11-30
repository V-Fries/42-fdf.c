/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:12:39 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 19:36:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrices.h"
#include "mlx_tools.h"
#include "math.h"
#include "fdf.h"
#include "draw.h"

void	move_camera_y_x(t_fdf *fdf, int key)
{
	if (key == KEY_W)
	{
		fdf->cam.cam = vector_sub(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_S)
	{
		fdf->cam.cam = vector_add(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_D)
	{
		fdf->cam.cam.x -= CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_A)
	{
		fdf->cam.cam.x += CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
}

void	move_camera_up_down_rotation_z(t_fdf *fdf, int key)
{
	if (key == KEY_SPACE)
	{
		fdf->cam.cam.y += CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_SHIFT)
	{
		fdf->cam.cam.y -= CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_E)
	{
		fdf->mats.rot_z_rot += CAM_SPEED / M_PI;
		update_rot_z_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	else if (key == KEY_Q)
	{
		fdf->mats.rot_z_rot -= CAM_SPEED / M_PI;
		update_rot_z_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
}

void	move_camera_rotation(t_fdf *fdf, int key)
{
	if (key == KEY_UP)
	{
		fdf->mats.rot_x_rot += CAM_SPEED / M_PI;
		update_rot_x_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	else if (key == KEY_DOWN)
	{
		fdf->mats.rot_x_rot -= CAM_SPEED / M_PI;
		update_rot_x_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	else if (key == KEY_LEFT)
	{
		fdf->cam.yaw += CAM_SPEED / M_PI;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	else if (key == KEY_RIGHT)
	{
		fdf->cam.yaw -= CAM_SPEED / M_PI;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
}
