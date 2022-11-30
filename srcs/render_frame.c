/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:10 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 20:33:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "camera_fdf.h"
#include "draw.h"

static void	deal_key(t_fdf *fdf)
{
	int	*keys;

	keys = fdf->keys.keys;
	if (keys[KEY_ESC])
		close_window(&((t_fdf *)fdf)->win);
	if (keys[KEY_W] || keys[KEY_A] || keys[KEY_S] || keys[KEY_D])
		move_camera_y_x(fdf, keys);
	if (keys[KEY_SPACE] || keys[KEY_SHIFT] || keys[KEY_E] || keys[KEY_Q])
		move_camera_up_down_rotation_z(fdf, keys);
	if (keys[KEY_UP] || keys[KEY_DOWN] || keys[KEY_LEFT] || keys[KEY_RIGHT])
		move_camera_rotation(fdf, keys);
}

int	render_frame(t_fdf *fdf)
{
	if (fdf->keys.keys_pressed)
		deal_key(fdf);
	draw_fdf(fdf);
	return (0);
}
