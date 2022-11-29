/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 14:13:23 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"
#include "utils.h"
#include "line_drawing.h"
#include "ft_linked_list.h"
#include "projection_matrix.h"
#include "rotation_matrices.h"
#include "matrix_multiplication.h"
#include "world_matrix.h"
#include "vector.h"
#include "camera.h"
#include <stdlib.h>
#include <math.h>


void	fill_m_v_map(t_fdf *fdf)
{
	for (int y = 0; y < 11; y++)
		for (int x = 0; x < 19; x++)
		{
			fdf->map.m_v_map[y][x] = matrix_times_vector(&fdf->mats.world,
					&fdf->map.o_v_map[y][x]);

			fdf->map.m_v_map[y][x] = matrix_times_vector(&fdf->cam.view_m,
					&fdf->map.m_v_map[y][x]);

			fdf->map.m_v_map[y][x] = matrix_times_vector(&fdf->mats.proj,
					&fdf->map.m_v_map[y][x]);

			fdf->map.m_v_map[y][x] = vector_divide(&fdf->map.m_v_map[y][x],
					fdf->map.m_v_map[y][x].w);

			fdf->map.m_v_map[y][x].x += 1.0;
			fdf->map.m_v_map[y][x].y += 1.0;

			fdf->map.m_v_map[y][x].x *= 0.5 * (double)WINDOW_X;
			fdf->map.m_v_map[y][x].y *= 0.5 * (double)WINDOW_Y;
		}
}

void	draw_lines(t_fdf *fdf)
{
	t_2d_point_i	start;
	t_2d_point_i	end;

	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (x + 1 < 19)
			{
				start.x = fdf->map.m_v_map[y][x].x + 0.5;
				start.y = fdf->map.m_v_map[y][x].y + 0.5;
				end.x = fdf->map.m_v_map[y][x + 1].x + 0.5;
				end.y = fdf->map.m_v_map[y][x + 1].y + 0.5;
				draw_line(&fdf->img, start, end);
			}
			if (y + 1 < 11)
			{
				start.x = fdf->map.m_v_map[y][x].x + 0.5;
				start.y = fdf->map.m_v_map[y][x].y + 0.5;
				end.x = fdf->map.m_v_map[y + 1][x].x + 0.5;
				end.y = fdf->map.m_v_map[y + 1][x].y + 0.5;
				draw_line(&fdf->img, start, end);
			}
		}
	}
}

void	draw_fdf(t_fdf *fdf)
{
	fill_m_v_map(fdf);
	draw_lines(fdf);
	put_img(&fdf->img, &fdf->win);
}

void	redraw_fdf(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->img.y_size)
	{
		x = -1;
		while (++x < fdf->img.x_size)
			put_pixel_on_img(&fdf->img, y, x, 0x000000);
	}
	draw_fdf(fdf);
}

void	move_camera_y_x(t_fdf *fdf, int key)
{
	if (key == KEY_W)
	{
		fdf->cam.cam = vector_sub(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_S)
	{
		fdf->cam.cam = vector_add(&fdf->cam.cam, &fdf->cam.forward);
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_D)
	{
		fdf->cam.cam.x -= CAM_SPEED;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_A)
	{
		fdf->cam.cam.x += CAM_SPEED;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
}

void	move_camera_up_yaw(t_fdf *fdf, int key)
{
	if (key == KEY_SPACE)
	{
		fdf->cam.cam.y += CAM_SPEED;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_SHIFT)
	{
		fdf->cam.cam.y -= CAM_SPEED;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_LEFT)
	{
		fdf->cam.yaw += CAM_SPEED / M_PI;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
	else if (key == KEY_RIGHT)
	{
		fdf->cam.yaw -= CAM_SPEED / M_PI;
		update_camera(&fdf->cam);
		redraw_fdf(fdf);
	}
}

int	deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	ft_putstr("\n");
	if (key == KEY_ESC)
		return (close_window(&((t_fdf *)param)->win));
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		return (move_camera_y_x(param, key), 0);
	if (key == KEY_SPACE || key == KEY_SHIFT
		|| key == KEY_LEFT || key == KEY_RIGHT)
		return (move_camera_up_yaw(param, key), 0);
	// if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
	// 	return (change_camera_orientation(param, key), 0);
	(void)param;
	return (0);
}

void	init_fdf(t_fdf *fdf)
{
	static int	arr[11][19] =	{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
	fdf->map.y_size = 11;
	fdf->map.x_size = 19;
	fdf->map.i_map = malloc(sizeof(int *) * fdf->map.y_size);
	for (int i = 0; i < fdf->map.y_size; i++)
		fdf->map.i_map[i] = arr[i];
	fdf->map.o_v_map = malloc(sizeof(t_vector_d *) * fdf->map.y_size);
	fdf->map.m_v_map = malloc(sizeof(t_vector_d *) * fdf->map.y_size);
	for (int y = 0; y < fdf->map.y_size; y++)
	{
		fdf->map.o_v_map[y] = malloc(sizeof(t_vector_d) * fdf->map.x_size);
		fdf->map.m_v_map[y] = malloc(sizeof(t_vector_d) * fdf->map.x_size);
		for (int x = 0; x < fdf->map.x_size; x++)
		{
			fdf->map.o_v_map[y][x].x = x;
			fdf->map.o_v_map[y][x].y = y;
			fdf->map.o_v_map[y][x].z = arr[y][x];
			fdf->map.o_v_map[y][x].w = 1.0;
		}
	}
	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	fdf->mats.proj_m_data.z_near = 0.1f;
	fdf->mats.proj_m_data.z_far = 1000.0f;
	fdf->mats.proj_m_data.fov = 90.0f;
	fdf->mats.proj_m_data.aspect_ratio = (double)WINDOW_Y / (double)WINDOW_X;
	init_camera(&fdf->cam);
	fdf->mats.proj = get_projection_matrix(&fdf->mats.proj_m_data);
	fdf->mats.rot_z = get_rotation_z_matrix(0.0);
	fdf->mats.rot_x = get_rotation_x_matrix(0.0);
	fdf->mats.rot_y = get_rotation_y_matrix(0.0);
	fdf->mats.trans = get_translation_matrix(0.0, 0.0, -20.0);
	fdf->mats.world = get_world_matrix(&fdf->mats.rot_z, &fdf->mats.rot_x,
			&fdf->mats.rot_y, &fdf->mats.trans);
}

void	start_mlx(t_fdf *fdf)
{
	mlx_key_hook(fdf->win.win, &deal_key, fdf);
	mlx_loop(fdf->win.mlx);
}

int	main(void)
{
	t_fdf		fdf;

	init_fdf(&fdf);


	draw_fdf(&fdf);
	//move_camera_z(&fdf, 49);
	//move_camera_z(&fdf, 49);
	//move_camera_z(&fdf, 49);
	//move_camera_z(&fdf, 49);


	start_mlx(&fdf);
}
