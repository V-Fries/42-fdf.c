/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 00:37:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"
#include "utils.h"
#include "line_drawing.h"
#include "ft_linked_list.h"
#include "perspective_projection.h"
#include "projection_matrix.h"
#include "matrix_vector_multiplication.h"
#include "rotation_matrices.h"
#include <stdlib.h>
#include <math.h>


// void	move_camera_y_x(t_fdf *fdf, int key)
// {
// 	if (key == KEY_W)
// 	{
// 		fdf->camera.x++;
// 		fdf->orientation.x++;
// 		fdf->screen.x++;
// 	}
// 	else if (key == KEY_S)
// 	{
// 		fdf->camera.x--;
// 		fdf->orientation.x--;
// 		fdf->screen.x--;
// 	}
// 	else if (key == KEY_A)
// 	{
// 		fdf->camera.y++;
// 		fdf->orientation.y++;
// 		fdf->screen.y++;
// 	}
// 	else if (key == KEY_D)
// 	{
// 		fdf->camera.y--;
// 		fdf->orientation.y--;
// 		fdf->screen.y--;
// 	}
// }

// void	move_camera_z(t_fdf *fdf, int key)
// {
// 	if (key == KEY_SPACE)
// 	{
// 		fdf->camera.z++;
// 		fdf->orientation.z++;
// 		fdf->screen.z++;
// 	}
// 	if (key == KEY_SHIFT)
// 	{
// 		fdf->camera.z--;
// 		fdf->orientation.z--;
// 		fdf->screen.z--;
// 	}
// }

// void	change_camera_orientation(t_fdf *fdf, int key)
// {
// 	if (key == KEY_UP)
// 	{
// 		fdf->orientation.z--;
// 		fdf->screen.x++;
// 	}
// 	else if (key == KEY_DOWN)
// 	{
// 		fdf->orientation.x--;
// 		fdf->screen.x--;
// 	}
// 	else if (key == KEY_LEFT)
// 	{
// 		fdf->orientation.y++;
// 		fdf->screen.y++;
// 	}
// 	else if (key == KEY_RIGHT)
// 	{
// 		fdf->orientation.y--;
// 		fdf->screen.y--;
// 	}
// }

int	deal_key(int key, void *param)
{
	if (key == KEY_ESC)
		return (close_window(&((t_fdf *)param)->win));
	// if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	// 	return (move_camera_y_x(param, key), 0);
	// if (key == KEY_SPACE || key == KEY_SHIFT)
	// 	return (move_camera_z(param, key), 0);
	// if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
	// 	return (change_camera_orientation(param, key), 0);
	(void)param;
	ft_putnbr_fd(key, 1);
	ft_putstr("\n");
	return (0);
}

// t_3d_point_i	get_3d_point(int x, int y, int z)
// {
// 	t_3d_point_i	new;

// 	new.x = x;
// 	new.y = y;
// 	new.z = z;
// 	return (new);
// }

// void	add_line(t_fdf *fdf, t_3d_point_i start, t_3d_point_i end)
// {

// 	t_list *vectors = bresenham_3d(start, end);
// 	for (t_list *current = vectors; current; current = current->next)
// 	{
// 		t_2d_point_i pixel = perspective_projection(*((t_3d_point_i *)current->content), fdf->camera, fdf->orientation, fdf->screen);
// 		if (pixel.x < WINDOW_X && pixel.x >= 0 && pixel.y < WINDOW_Y && pixel.y >= 0)
// 			put_pixel_on_img(&fdf->img, pixel.y, pixel.x, 0xFFFFFF);
// 	}
// 	ft_lstclear(&vectors, &free);
// }

void	init_fdf(t_fdf *fdf)
{
	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	fdf->proj_m_data.z_near = 0.1f;
	fdf->proj_m_data.z_far = 1000.0f;
	fdf->proj_m_data.fov = 90.0f;
	fdf->proj_m_data.aspect_ratio = (double)WINDOW_Y / (double)WINDOW_X;
}

void	start_mlx(t_fdf *fdf)
{
	mlx_key_hook(fdf->win.win, &deal_key, &fdf);
	mlx_loop(fdf->win.mlx);
}

int	main(void)
{
	t_fdf		fdf;

	init_fdf(&fdf);


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

	t_matrix_4 proj_m = get_projection_matrix(&fdf.proj_m_data);
	// t_matrix_4 rot_z_m = get_rotation_z_matrix(90.0);
	t_matrix_4 rot_x_m = get_rotation_x_matrix(180.0);

	t_3d_point_d	vectors[11][19];
	for (int y = 0; y < 11; y++)
		for (int x = 0; x < 19; x++)
		{
			vectors[y][x].x = x;
			vectors[y][x].y = y;
			vectors[y][x].z = arr[y][x] - 20.0f;

			t_3d_point_d tmp = vectors[y][x];
			// matrix_vector_multiplication(&tmp, &vectors[y][x], &rot_z_m);
			// tmp = vectors[y][x];
			matrix_vector_multiplication(&tmp, &vectors[y][x], &rot_x_m);
			tmp = vectors[y][x];

			matrix_vector_multiplication(&tmp, &vectors[y][x], &proj_m);

			vectors[y][x].x += 1.0f;
			vectors[y][x].y += 1.0f;

			vectors[y][x].x *= 0.5f * (double)WINDOW_X;
			vectors[y][x].y *= 0.5f * (double)WINDOW_Y;
		}

	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (x + 1 < 19)
			{
				t_2d_point_i start;
				t_2d_point_i end;

				start.x = vectors[y][x].x + 0.5f;
				start.y = vectors[y][x].y + 0.5f;
				end.x = vectors[y][x + 1].x + 0.5f;
				end.y = vectors[y][x + 1].y + 0.5f;
				draw_line(&fdf.img, start, end);
			}
			if (y + 1 < 11)
			{
				t_2d_point_i start;
				t_2d_point_i end;

				start.x = vectors[y][x].x + 0.5f;
				start.y = vectors[y][x].y + 0.5f;
				end.x = vectors[y + 1][x].x + 0.5f;
				end.y = vectors[y + 1][x].y + 0.5f;
				draw_line(&fdf.img, start, end);
			}
		}
	}


	put_img(&fdf.img, &fdf.win);



	start_mlx(&fdf);
}
