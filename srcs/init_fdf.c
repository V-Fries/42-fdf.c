/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:06:33 by vfries            #+#    #+#             */
/*   Updated: 2022/12/02 02:14:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>
#include <math.h>

#include <stdlib.h>

static int	parse_map(t_fdf *fdf, char *map_name)
{
	int					highest_point;
	int	arr[11][19] =	{{0,  0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0},
						 {0,  0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0},
						 {0,  0, 10, 10, 0,  0,  10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0,  0, 0},
						 {0,  0, 10, 10, 0,  0,  10, 10, 0, 0, 0, 0,  0,  0,  0,  10, 10, 0, 0},
						 {0,  0, 10, 10, 0,  0,  10, 10, 0, 0, 0, 0,  0,  0,  0,  10, 10, 0, 0},
						 {0,  0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0,  10, 10, 10, 10, 0,  0, 0},
						 {0,  0, 0,  10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0,  0,  0,  0,  0, 0},
						 {0,  0, 0,  0,  0,  0,  10, 10, 0, 0, 0, 10, 10, 0,  0,  0,  0,  0, 0},
						 {0,  0, 0,  0,  0,  0,  10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
						 {0,  0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0},
						 {0,  0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0}};

	(void)map_name;
	highest_point = INT_MIN;
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
			if (arr[y][x] > highest_point)
				highest_point = arr[y][x];
			fdf->map.o_v_map[y][x].x = x - fdf->map.x_size / 2;
			fdf->map.o_v_map[y][x].y = y - fdf->map.y_size / 2;
			fdf->map.o_v_map[y][x].z = -arr[y][x];
			fdf->map.o_v_map[y][x].w = 1.0;
		}
	}
	return (highest_point);
}

static void	init_matrices(t_fdf *fdf, int decal)
{
	fdf->mats.proj.z_near = 0.1;
	fdf->mats.proj.z_far = 1000.0;
	fdf->mats.proj.fov = 90.0;
	fdf->mats.proj.aspect_ratio = (double)WINDOW_Y / (double)WINDOW_X;
	fdf->mats.proj.m = get_prespective_proj_matrix(&fdf->mats.proj);
	fdf->mats.proj.type = 0;
	fdf->mats.rot_z.rot = 0.0;
	fdf->mats.rot_z.m = get_rotation_z_matrix(fdf->mats.rot_z.rot);
	fdf->mats.rot_x.rot = 0.0;
	fdf->mats.rot_x.m = get_rotation_x_matrix(fdf->mats.rot_x.rot);
	fdf->mats.rot_y.rot = 0.0;
	fdf->mats.rot_y.m = get_rotation_y_matrix(fdf->mats.rot_y.rot);
	fdf->mats.trans.x = 0.0;
	fdf->mats.trans.y = 0.0;
	if (fdf->map.x_size > fdf->map.y_size && fdf->map.x_size > decal)
		decal = fdf->map.x_size;
	else if (fdf->map.y_size > decal)
		decal = fdf->map.y_size;
	fdf->mats.trans.z = decal;
	fdf->mats.trans.m = get_translation_matrix(fdf->mats.trans.x,
			fdf->mats.trans.y, fdf->mats.trans.z);
	fdf->mats.world = get_world_matrix(&fdf->mats.rot_z.m, &fdf->mats.rot_x.m,
			&fdf->mats.rot_y.m, &fdf->mats.trans.m);
}

void	init_fdf(t_fdf *fdf, char *map_name)
{
	int		highest_point;
	short	i;

	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	highest_point = parse_map(fdf, map_name);
	i = -1;
	while (++i < MAX_KEY)
		fdf->keys.keys[i] = 0;
	fdf->keys.keys_pressed = 0;
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	init_matrices(fdf, highest_point);
}
