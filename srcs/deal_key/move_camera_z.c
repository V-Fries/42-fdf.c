/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:59:30 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 18:04:42 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_camera_key_w(t_fdf *fdf)
{
	if (fdf->mats.proj.type == PROJ_ISOMETRIC)
	{
		fdf->iso_scale += fdf->cam_speed * 0.01 + (fdf->iso_scale * 0.01);
		fdf->mats.proj.m = get_scale_matrix(fdf->iso_scale);
		return ;
	}
	fdf->mats.trans.z -= fdf->cam_speed;
	if (fdf->mats.trans.z < 0)
		fdf->mats.trans.z = 0;
	update_translation_matrix(&fdf->mats);
}

static void	move_camera_key_s(t_fdf *fdf)
{
	if (fdf->mats.proj.type == PROJ_PERSEPECTIVE)
	{
		fdf->mats.trans.z += fdf->cam_speed;
		update_translation_matrix(&fdf->mats);
		return ;
	}
	if (fdf->iso_scale >= 1)
		fdf->iso_scale -= fdf->cam_speed * 0.01
			+ (fdf->iso_scale * 0.01);
	fdf->mats.proj.m = get_scale_matrix(fdf->iso_scale);
}

void	move_camera_z(t_fdf *fdf, int *keys)
{
	if (keys[KEY_W])
		move_camera_key_w(fdf);
	else
		move_camera_key_s(fdf);
}
