/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:46:27 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 22:48:29 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "utils.h"
#include <stddef.h>

t_matrix_4	get_world_matrix(t_matrix_4 *rot_z, t_matrix_4 *rot_x,
				t_matrix_4 *rot_y, t_matrix_4 *trans)
{
	t_matrix_4	world_matrix;

	world_matrix = matrix_times_matrix(rot_z, rot_x);
	world_matrix = matrix_times_matrix(&world_matrix, rot_y);
	world_matrix = matrix_times_matrix(&world_matrix, trans);
	return (world_matrix);
}

void	update_translation_matrix(t_matrices *mats)
{
	mats->trans.m = get_translation_matrix(mats->trans.x, mats->trans.y,
			mats->trans.z);
	mats->world = get_world_matrix(&mats->rot_z.m, &mats->rot_x.m,
			&mats->rot_y.m, &mats->trans.m);
}

void	update_rot_z_matrix(t_matrices *mats)
{
	mats->rot_z.m = get_rotation_z_matrix(mats->rot_z.rot);
	mats->world = get_world_matrix(&mats->rot_z.m, &mats->rot_x.m,
			&mats->rot_y.m, &mats->trans.m);
}

void	update_rot_x_matrix(t_matrices *mats)
{
	mats->rot_x.m = get_rotation_x_matrix(mats->rot_x.rot);
	mats->world = get_world_matrix(&mats->rot_z.m, &mats->rot_x.m,
			&mats->rot_y.m, &mats->trans.m);
}

void	update_rot_y_matrix(t_matrices *mats)
{
	mats->rot_y.m = get_rotation_y_matrix(mats->rot_y.rot);
	mats->world = get_world_matrix(&mats->rot_z.m, &mats->rot_x.m,
			&mats->rot_y.m, &mats->trans.m);
}
