/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:06:33 by vfries            #+#    #+#             */
/*   Updated: 2022/12/07 15:14:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "parsing.h"
#include <math.h>

#include <limits.h>
#include <stdlib.h>

static void	init_matrices(t_fdf *fdf, double decal)
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

static double	rot_speed_calculator(t_fdf *fdf)
{
	int	n;
	int	i;

	n = fdf->map.x_size + fdf->map.y_size;
	i = 10;
	while (n)
	{
		i--;
		n /= 10;
	}
	if (i == 0)
		return (0.25 * 1.0 * 0.025);
	return (0.25 * (double)i * 0.025);
}

static double	move_speed_calculator(t_fdf *fdf)
{
	int		multiplied;
	int		divisor;
	double	tmp;

	multiplied = fdf->map.x_size * fdf->map.y_size;
	tmp = multiplied;
	divisor = 1;
	while (multiplied)
	{
		multiplied /= 10;
		divisor++;
	}
	tmp = tmp / (double)divisor;
	if (tmp > 500.0)
		return (tmp * 0.0001);
	return (0.25);
}

void	init_fdf(t_fdf *fdf, char *map_name)
{
	short	i;

	fdf->win.mlx = mlx_init();
	fdf->win.win = mlx_new_window(fdf->win.mlx, WINDOW_X, WINDOW_Y, "fdf");
	fdf->map.highest_point = parse_map(&fdf->map, map_name);
	fdf->cam_rot_speed = rot_speed_calculator(fdf);
	fdf->cam_speed = move_speed_calculator(fdf);
	i = -1;
	while (++i < MAX_KEY)
		fdf->keys.keys[i] = 0;
	fdf->keys.keys_pressed = 0;
	init_image(&fdf->img, &fdf->win, WINDOW_Y, WINDOW_X);
	init_matrices(fdf, -fdf->map.highest_point);
	fdf->view_mode = PROJ_PERSEPECTIVE;
	fdf->colors = false;
}
