#include "fdf.h"
#include "mlx.h"
#include <limits.h>
#include <math.h>

#include <stdlib.h>

static int	init_piece_of_shit(t_fdf *fdf)
{
	int					lowest_point;
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

	lowest_point = INT_MAX;
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
			if (arr[y][x] < lowest_point)
				lowest_point = arr[y][x];
			fdf->map.o_v_map[y][x].x = x - fdf->map.x_size / 2;
			fdf->map.o_v_map[y][x].y = y - fdf->map.y_size / 2;
			fdf->map.o_v_map[y][x].z = arr[y][x];
			fdf->map.o_v_map[y][x].w = 1.0;
		}
	}
	return (lowest_point);
}

static void	init_matrices(t_fdf *fdf, int lowest_point)
{
	fdf->mats.proj.z_near = 0.1f;
	fdf->mats.proj.z_far = 1000.0f;
	fdf->mats.proj.fov = 90.0f;
	fdf->mats.proj.aspect_ratio = (double)WINDOW_Y / (double)WINDOW_X;
	fdf->mats.proj.m = get_projection_matrix(&fdf->mats.proj);
	fdf->mats.rot_z.rot = M_PI;
	fdf->mats.rot_z.m = get_rotation_z_matrix(fdf->mats.rot_z.rot);
	fdf->mats.rot_x.rot = 0.0;
	fdf->mats.rot_x.m = get_rotation_x_matrix(fdf->mats.rot_x.rot);
	fdf->mats.rot_y.rot = 0.0;
	fdf->mats.rot_y.m = get_rotation_y_matrix(fdf->mats.rot_y.rot);
	fdf->mats.trans.x = 0.0;
	fdf->mats.trans.y = 0.0;
	fdf->mats.trans.z = lowest_point - 20.0;
	fdf->mats.trans.m = get_translation_matrix(fdf->mats.trans.x,
			fdf->mats.trans.y, fdf->mats.trans.z);
	fdf->mats.world = get_world_matrix(&fdf->mats.rot_z.m, &fdf->mats.rot_x.m,
			&fdf->mats.rot_y.m, &fdf->mats.trans.m);
}

void	init_fdf(t_fdf *fdf)
{
	int		lowest_point;
	short	i;

	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	lowest_point = init_piece_of_shit(fdf);
	i = -1;
	while (++i < MAX_KEY)
		fdf->keys.keys[i] = 0;
	fdf->keys.keys_pressed = 0;
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	init_matrices(fdf, lowest_point);
}
