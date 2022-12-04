/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:10 by vfries            #+#    #+#             */
/*   Updated: 2022/12/04 09:39:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "move_camera.h"
#include "draw.h"

static void	update_proj_mat(t_proj_m *proj, int *keys)
{
	if (proj->type == 0)
	{
		proj->m = get_iso_proj_matrix(proj);
		proj->type = 1;
	}
	else if (proj->type == 1)
	{
		proj->m = get_prespective_proj_matrix(proj);
		proj->type = 0;
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
		update_proj_mat(&fdf->mats.proj, keys);
	if (keys[KEY_V])
		change_view(fdf);
}

int	render_frame(t_fdf *fdf)
{
	if (fdf->keys.keys_pressed)
		deal_key(fdf);
	draw_fdf(fdf);
	return (0);
}
