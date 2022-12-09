/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:12:39 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 18:03:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "move_camera.h"
#include <math.h>

void	move_camera_y_x(t_fdf *fdf, int *keys)
{
	if (keys[KEY_W] || keys[KEY_S])
		move_camera_z(fdf, keys);
	if (keys[KEY_D])
	{
		fdf->mats.trans.x -= fdf->cam_speed;
		update_translation_matrix(&fdf->mats);
	}
	if (keys[KEY_A])
	{
		fdf->mats.trans.x += fdf->cam_speed;
		update_translation_matrix(&fdf->mats);
	}
}

static void	secure_rot(double *rot)
{
	if (*rot > M_PI * 4)
		*rot -= M_PI * 4;
	else if (*rot < M_PI * 4)
		*rot += M_PI * 4;
}

void	move_camera_up_down_rotation_z(t_fdf *fdf, int *keys)
{
	if (keys[KEY_SPACE])
	{
		fdf->mats.trans.y += fdf->cam_speed;
		update_translation_matrix(&fdf->mats);
	}
	if (keys[KEY_L_SHIFT])
	{
		fdf->mats.trans.y -= fdf->cam_speed;
		update_translation_matrix(&fdf->mats);
	}
	if (keys[KEY_E])
	{
		fdf->mats.rot_z.rot += fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_z.rot);
		update_rot_z_matrix(&fdf->mats);
	}
	if (keys[KEY_Q])
	{
		fdf->mats.rot_z.rot -= fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_z.rot);
		update_rot_z_matrix(&fdf->mats);
	}
}

void	move_camera_rotation(t_fdf *fdf, int *keys)
{
	if (keys[KEY_UP])
	{
		fdf->mats.rot_x.rot += fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_x.rot);
		update_rot_x_matrix(&fdf->mats);
	}
	if (keys[KEY_DOWN])
	{
		fdf->mats.rot_x.rot -= fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_x.rot);
		update_rot_x_matrix(&fdf->mats);
	}
	if (keys[KEY_LEFT])
	{
		fdf->mats.rot_y.rot += fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_y.rot);
		update_rot_y_matrix(&fdf->mats);
	}
	if (keys[KEY_RIGHT])
	{
		fdf->mats.rot_y.rot -= fdf->cam_rot_speed;
		secure_rot(&fdf->mats.rot_y.rot);
		update_rot_y_matrix(&fdf->mats);
	}
}
