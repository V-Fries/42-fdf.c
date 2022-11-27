/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 00:56:46 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"
#include "mlx_tools.h"
#include "utils.h"
#include "line_drawing.h"
#include "bresenham_3d.h"
#include "ft_linked_list.h"
#include "perspective_projection.h"
#include <stdlib.h>

#define WINDOW_X 1400
#define WINDOW_Y 800

int	deal_key(int key, void *param)
{
	if (key == ESC)
		return (close_window(param));
	ft_putnbr_fd(key, 1);
	return (0);
}

int	main(void)
{
	t_win		win;
	t_img		img;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&img, &win, WINDOW_Y, WINDOW_X);

	t_3d_point	camera;
	camera.x = 0;
	camera.y = 0;
	camera.z = 3000;

	t_3d_point	orientation;
	orientation.x = 0;
	orientation.y = 0;
	orientation.z = 2900;

	t_3d_point	screen;
	screen.x = 0;
	screen.y = 0;
	screen.z = 2700;

	t_3d_point	start;
	t_3d_point	end;
	start.x = 100;
	start.y = 100;
	start.z = 50;
	end.x = -500;
	end.y = 10000;
	end.z = 400;
	//int x = 1;
	while (end.x < 2000)
	{
		t_list *vectors = bresenham_3d(start, end);
		for (t_list *current = vectors; current; current = current->next)
		{
			t_2d_point *pixel = perspective_projection(*((t_3d_point *)current->content), camera, orientation, screen);
			if (pixel->x < WINDOW_X && pixel->x >= 0 && pixel->y < WINDOW_Y && pixel->y >= 0)
				put_pixel_on_img(&img, pixel->y, pixel->x, 0xFFFFFF);
			free(pixel);
		}
		ft_lstclear(&vectors, &free);
		end.x++;
	}


	put_img(&img, &win);
	mlx_key_hook(win.win, &deal_key, &win);
	mlx_loop(win.mlx);
}
