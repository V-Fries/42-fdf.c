/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:01:16 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 20:29:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "render_frame.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	key_down(int key, t_fdf *fdf)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	fdf->keys.keys[key] = 1;
	fdf->keys.keys_pressed++;
	return (0);
}

int	key_up(int key, t_fdf *fdf)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	fdf->keys.keys[key] = 0;
	fdf->keys.keys_pressed--;
	return (0);
}

void	start_mlx(t_fdf *fdf)
{
	mlx_hook(fdf->win.win, ON_KEYDOWN, 2, &key_down, fdf);
	mlx_hook(fdf->win.win, ON_KEYUP, 3, &key_up, fdf);
	//mlx_key_hook(fdf->win.win, &deal_key, fdf);
	mlx_loop_hook(fdf->win.mlx, &render_frame, fdf);
	mlx_loop(fdf->win.mlx);
}
