/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 11:47:02 by vfries           ###   ########lyon.fr   */
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

typedef struct s_fdf
{
	t_win		win;
	t_img		img;
	t_3d_point	camera;
	t_3d_point	orientation;
	t_3d_point	screen;
}	t_fdf;

void	move_camera_y_x(t_fdf *fdf, int key)
{
	if (key == KEY_W)
	{
		fdf->camera.x++;
		fdf->orientation.x++;
		fdf->screen.x++;
	}
	else if (key == KEY_S)
	{
		fdf->camera.x--;
		fdf->orientation.x--;
		fdf->screen.x--;
	}
	else if (key == KEY_A)
	{
		fdf->camera.y++;
		fdf->orientation.y++;
		fdf->screen.y++;
	}
	else if (key == KEY_D)
	{
		fdf->camera.y--;
		fdf->orientation.y--;
		fdf->screen.y--;
	}
}

void	move_camera_z(t_fdf *fdf, int key)
{
	if (key == KEY_SPACE)
	{
		fdf->camera.z++;
		fdf->orientation.z++;
		fdf->screen.z++;
	}
	if (key == KEY_SHIFT)
	{
		fdf->camera.z--;
		fdf->orientation.z--;
		fdf->screen.z--;
	}
}

void	change_camera_orientation(t_fdf *fdf, int key)
{
	if (key == KEY_UP)
	{
		fdf->orientation.z--;
		fdf->screen.x++;
	}
	else if (key == KEY_DOWN)
	{
		fdf->orientation.x--;
		fdf->screen.x--;
	}
	else if (key == KEY_LEFT)
	{
		fdf->orientation.y++;
		fdf->screen.y++;
	}
	else if (key == KEY_RIGHT)
	{
		fdf->orientation.y--;
		fdf->screen.y--;
	}
}

int	deal_key(int key, void *param)
{
	if (key == KEY_ESC)
		return (close_window(&((t_fdf *)param)->win));
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		return (move_camera_y_x(param, key), 0);
	if (key == KEY_SPACE || key == KEY_SHIFT)
		return (move_camera_z(param, key), 0);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (change_camera_orientation(param, key), 0);
	ft_putnbr_fd(key, 1);
	ft_putstr("\n");
	return (0);
}

t_3d_point	get_3d_point(int x, int y, int z)
{
	t_3d_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void	add_line(t_fdf *fdf, t_3d_point start, t_3d_point end)
{

	t_list *vectors = bresenham_3d(start, end);
	for (t_list *current = vectors; current; current = current->next)
	{
		t_2d_point pixel = perspective_projection(*((t_3d_point *)current->content), fdf->camera, fdf->orientation, fdf->screen);
		if (pixel.x < WINDOW_X && pixel.x >= 0 && pixel.y < WINDOW_Y && pixel.y >= 0)
			put_pixel_on_img(&fdf->img, pixel.y, pixel.x, 0xFFFFFF);
	}
	ft_lstclear(&vectors, &free);
}

int	main(void)
{
	t_fdf		fdf;

	fdf.win.mlx = mlx_init();
	fdf.win.win = mlx_new_window(fdf.win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&fdf.img, &fdf.win, WINDOW_Y, WINDOW_X);

	int	arr[11][19] =	{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
							{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
							{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
							{0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
							{0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (x + 1 < 19)
				add_line(&fdf, get_3d_point(x, y, arr[y][x]), get_3d_point(x + 1, y, arr[y][x + 1]));
			if (y + 1 < 11)
				add_line(&fdf, get_3d_point(x, y, arr[y][x]), get_3d_point(x + 1, y, arr[y + 1][x]));
		}
	}

	// while (end.x < 2000)
	// {
	// 	t_list *vectors = bresenham_3d(start, end);
	// 	for (t_list *current = vectors; current; current = current->next)
	// 	{
	// 		t_2d_point *pixel = perspective_projection(*((t_3d_point *)current->content), camera, orientation, screen);
	// 		if (pixel->x < WINDOW_X && pixel->x >= 0 && pixel->y < WINDOW_Y && pixel->y >= 0)
	// 			put_pixel_on_img(&fdf.img, pixel->y, pixel->x, 0xFFFFFF);
	// 		free(pixel);
	// 	}
	// 	ft_lstclear(&vectors, &free);
	// 	end.x++;
	// }


	put_img(&fdf.img, &fdf.win);
	mlx_key_hook(fdf.win.win, &deal_key, &fdf);
	mlx_loop(fdf.win.mlx);
}
