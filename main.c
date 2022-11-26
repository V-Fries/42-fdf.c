/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/26 16:51:54 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"
#include "mlx_tools.h"
#include "utils.h"
#include "line_drawing.h"

#define WINDOW_X 1080
#define WINDOW_Y 1080

int	deal_key(int key, void *param)
{
	if (key == ESC)
		return (close_window(param));
	ft_putnbr_fd(key, 1);
	return (0);
}

int	main(void)
{
	t_win	win;
	t_img	img;
	t_coord	start = {100, 100};
	t_coord	end = {800, 100};

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&img, &win, WINDOW_Y, WINDOW_X);
	draw_line(&img, start, end);
	put_img(&img, &win);
	mlx_key_hook(win.win, &deal_key, &win);
	mlx_loop(win.mlx);
}
