/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 22:09:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "start_mlx.h"
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
	for (int i = 0; i < MAX_KEY; i++)
		fdf->keys.keys[i] = 0;
	fdf->keys.keys_pressed = 0;
	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	fdf->mats.proj_m_data.z_near = 0.1f;
	fdf->mats.proj_m_data.z_far = 1000.0f;
	fdf->mats.proj_m_data.fov = 90.0f;
	fdf->mats.proj_m_data.aspect_ratio = (double)WINDOW_Y / (double)WINDOW_X;
	init_camera(&fdf->cam);
	fdf->mats.proj = get_projection_matrix(&fdf->mats.proj_m_data);
	fdf->mats.rot_z_rot = 0.0;
	fdf->mats.rot_z = get_rotation_z_matrix(fdf->mats.rot_z_rot);
	fdf->mats.rot_x_rot = 0.0;
	fdf->mats.rot_x = get_rotation_x_matrix(fdf->mats.rot_x_rot);
	fdf->mats.rot_y_rot = 0.0;
	fdf->mats.rot_y = get_rotation_y_matrix(fdf->mats.rot_y_rot);
	fdf->mats.trans = get_translation_matrix(0.0, 0.0, -20.0);
	fdf->mats.world = get_world_matrix(&fdf->mats.rot_z, &fdf->mats.rot_x,
			&fdf->mats.rot_y, &fdf->mats.trans);
}

int	main(void)
{
	t_fdf		fdf;

	init_fdf(&fdf);


	draw_fdf(&fdf);


	start_mlx(&fdf);
}
