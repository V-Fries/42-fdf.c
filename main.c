/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 19:31:11 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"
#include "fdf.h"
#include "draw.h"
#include "ft_linked_list.h"
#include "matrices.h"
#include "vector.h"
#include "camera.h"
#include "camera_fdf.h"
#include <stdlib.h>
#include <math.h>

int	deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	ft_putstr("\n");
	if (key == KEY_ESC)
		return (close_window(&((t_fdf *)param)->win));
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		return (move_camera_y_x(param, key), 0);
	if (key == KEY_SPACE || key == KEY_SHIFT || key == KEY_E || key == KEY_Q)
		return (move_camera_up_down_rotation_z(param, key), 0);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (move_camera_rotation(param, key), 0);
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
	fdf->mats.rot_z_rot = 0.0;
	fdf->mats.rot_x = get_rotation_x_matrix(0.0);
	fdf->mats.rot_x_rot = 0.0;
	fdf->mats.rot_y = get_rotation_y_matrix(0.0);
	fdf->mats.trans = get_translation_matrix(0.0, 0.0, -20.0);
	fdf->mats.world = get_world_matrix(&fdf->mats.rot_z, &fdf->mats.rot_x,
			&fdf->mats.rot_y, &fdf->mats.trans);
}

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
	while (fdf->keys.keys[key])
		deal_key(key, fdf);
	return (0);
}

int	key_up(int key, t_fdf *fdf)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	fdf->keys.keys[key] = 0;
	return (0);
}

void	start_mlx(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < MAX_KEY)
		fdf->keys.keys[i] = 0;
	//mlx_hook(fdf->win.win, ON_KEYDOWN, 2, &key_down, fdf);
	//mlx_hook(fdf->win.win, ON_KEYUP, 3, &key_up, fdf);
	mlx_key_hook(fdf->win.win, &deal_key, fdf);
	mlx_loop(fdf->win.mlx);
}

int	main(void)
{
	t_fdf		fdf;

	init_fdf(&fdf);


	draw_fdf(&fdf);


	start_mlx(&fdf);
}
