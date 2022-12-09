/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:04:41 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 17:32:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "move_camera.h"

static void	update_proj_mat(t_fdf *fdf, int *keys)
{
	if (fdf->mats.proj.type == PROJ_PERSEPECTIVE)
	{
		fdf->mats.proj.m = get_scale_matrix(fdf->iso_scale);
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

static void	change_altitude(t_fdf *fdf)
{
	int		y;
	int		x;
	double	change;

	if (fdf->keys.keys[KEY_SEMI_COLON] && fdf->keys.keys[KEY_S_QUOTE])
		return ;
	if (fdf->keys.keys[KEY_S_QUOTE])
		change = 1.0;
	else
		change = -1.0;
	y = -1;
	while (++y < fdf->map.y_size)
	{
		x = -1;
		while (++x < fdf->map.x_size)
			fdf->map.a[y][x].z += (fdf->map.o[y][x].z / 50.0) * change;
	}
}

void	deal_key(t_fdf *fdf)
{
	int	*keys;

	keys = fdf->keys.keys;
	if (keys[KEY_ESC])
		close_window(&fdf->win);
	if (keys[KEY_W] || keys[KEY_A] || keys[KEY_S] || keys[KEY_D])
		move_camera_y_x(fdf, keys);
	if (keys[KEY_SPACE] || keys[KEY_L_SHIFT] || keys[KEY_E] || keys[KEY_Q])
		move_camera_up_down_rotation_z(fdf, keys);
	if (keys[KEY_UP] || keys[KEY_DOWN] || keys[KEY_LEFT] || keys[KEY_RIGHT])
		move_camera_rotation(fdf, keys);
	if (keys[KEY_P])
		update_proj_mat(fdf, keys);
	if (keys[KEY_V])
		change_view(fdf);
	if (keys[KEY_C])
		change_color(fdf);
	if (keys[KEY_SEMI_COLON] || keys[KEY_S_QUOTE])
		change_altitude(fdf);
}
