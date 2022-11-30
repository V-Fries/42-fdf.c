/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:46:27 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 21:27:16 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "utils.h"
#include <stddef.h>

t_matrix_4	get_translation_matrix(double x, double y, double z)
{
	t_matrix_4	m;

	mlx_tools_b_zero(&m, sizeof(t_matrix_4));
	m.m[0][0] = 1.0;
	m.m[1][1] = 1.0;
	m.m[2][2] = 1.0;
	m.m[3][3] = 1.0;
	m.m[3][0] = x;
	m.m[3][1] = y;
	m.m[3][2] = z;
	return (m);
}

t_matrix_4	get_world_matrix(t_matrix_4 *rot_z, t_matrix_4 *rot_x,
				t_matrix_4 *rot_y, t_matrix_4 *trans)
{
	t_matrix_4	world_matrix;

	world_matrix = matrix_times_matrix(rot_z, rot_x);
	world_matrix = matrix_times_matrix(&world_matrix, rot_y);
	world_matrix = matrix_times_matrix(&world_matrix, trans);
	return (world_matrix);
}

void	update_rot_z_matrix(t_matrices *mats)
{
	mats->rot_z = get_rotation_z_matrix(mats->rot_z_rot);
	mats->world = get_world_matrix(&mats->rot_z, &mats->rot_x, &mats->rot_y,
			&mats->trans);
}

void	update_rot_x_matrix(t_matrices *mats)
{
	mats->rot_x = get_rotation_x_matrix(mats->rot_x_rot);
	mats->world = get_world_matrix(&mats->rot_z, &mats->rot_x, &mats->rot_y,
			&mats->trans);
}

void	update_rot_y_matrix(t_matrices *mats)
{
	mats->rot_y = get_rotation_y_matrix(mats->rot_y_rot);
	mats->world = get_world_matrix(&mats->rot_z, &mats->rot_x, &mats->rot_y,
			&mats->trans);
}
