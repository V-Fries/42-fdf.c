/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:12:39 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 21:31:19 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrices.h"
#include "mlx_tools.h"
#include "math.h"
#include "fdf.h"
#include "draw.h"

void	move_camera_y_x(t_fdf *fdf, int *keys)
{
	if (keys[KEY_W])
	{
		fdf->cam.cam = vector_sub(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	if (keys[KEY_S])
	{
		fdf->cam.cam = vector_add(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	if (keys[KEY_D])
	{
		fdf->cam.cam.x -= CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	if (keys[KEY_A])
	{
		fdf->cam.cam.x += CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
}

void	move_camera_up_down_rotation_z(t_fdf *fdf, int *keys)
{
	if (keys[KEY_SPACE])
	{
		fdf->cam.cam.y += CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	if (keys[KEY_SHIFT])
	{
		fdf->cam.cam.y -= CAM_SPEED;
		update_camera(&fdf->cam);
		draw_fdf(fdf);
	}
	if (keys[KEY_E])
	{
		fdf->mats.rot_z_rot += CAM_SPEED / M_PI;
		update_rot_z_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	if (keys[KEY_Q])
	{
		fdf->mats.rot_z_rot -= CAM_SPEED / M_PI;
		update_rot_z_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
}

void	move_camera_rotation(t_fdf *fdf, int *keys)
{
	if (keys[KEY_UP])
	{
		fdf->mats.rot_x_rot += CAM_SPEED / M_PI;
		update_rot_x_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	if (keys[KEY_DOWN])
	{
		fdf->mats.rot_x_rot -= CAM_SPEED / M_PI;
		update_rot_x_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
	if (keys[KEY_LEFT])
	{
		fdf->mats.rot_y_rot += CAM_SPEED / M_PI;
		update_rot_y_matrix(&fdf->mats);
		draw_fdf(fdf);
		// fdf->cam.yaw += CAM_SPEED / M_PI;
		// update_camera(&fdf->cam);
		// draw_fdf(fdf);
	}
	if (keys[KEY_RIGHT])
	{
		fdf->mats.rot_y_rot -= CAM_SPEED / M_PI;
		update_rot_y_matrix(&fdf->mats);
		draw_fdf(fdf);
	}
}
