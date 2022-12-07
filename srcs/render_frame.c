/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:10 by vfries            #+#    #+#             */
/*   Updated: 2022/12/07 15:48:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "move_camera.h"
#include "draw.h"

static void	update_proj_mat(t_fdf *fdf, int *keys)
{
	if (fdf->mats.proj.type == PROJ_PERSEPECTIVE)
	{
		fdf->mats.proj.m = get_scale_matrix((fdf->mats.trans.z / fdf->map.y_size
					* fdf->map.x_size) * 0.0025);
		fdf->mats.proj.type = PROJ_ISOMETRIC;
	}
	else if (fdf->mats.proj.type == PROJ_ISOMETRIC)
	{
		fdf->mats.proj.m = get_prespective_proj_matrix(&fdf->mats.proj);
		fdf->mats.proj.type = PROJ_PERSEPECTIVE;
	}
	keys[KEY_P] = 0;
}

static void	change_view(t_fdf *fdf)
{
	if (fdf->view_mode == VIEW_POINTS)
		fdf->view_mode = VIEW_LINES;
	else
		fdf->view_mode = VIEW_POINTS;
	fdf->keys.keys[KEY_V] = 0;
}

static void	change_color(t_fdf *fdf)
{
	if (fdf->colors == true)
		fdf->colors = false;
	else
		fdf->colors = true;
	fdf->keys.keys[KEY_C] = 0;
}

static void	deal_key(t_fdf *fdf)
{
	int	*keys;

	keys = fdf->keys.keys;
	if (keys[KEY_ESC])
		close_window(&fdf->win);
	if (keys[KEY_W] || keys[KEY_A] || keys[KEY_S] || keys[KEY_D])
		move_camera_y_x(fdf, keys);
	if (keys[KEY_SPACE] || keys[KEY_SHIFT] || keys[KEY_E] || keys[KEY_Q])
		move_camera_up_down_rotation_z(fdf, keys);
	if (keys[KEY_UP] || keys[KEY_DOWN] || keys[KEY_LEFT] || keys[KEY_RIGHT])
		move_camera_rotation(fdf, keys);
	if (keys[KEY_P])
		update_proj_mat(fdf, keys);
	if (keys[KEY_V])
		change_view(fdf);
	if (keys[KEY_C])
		change_color(fdf);
}

int	render_frame(t_fdf *fdf)
{
	if (fdf->keys.keys_pressed)
		deal_key(fdf);
	draw_fdf(fdf);
	return (0);
}
