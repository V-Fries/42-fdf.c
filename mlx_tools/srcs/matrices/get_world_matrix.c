/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:46:27 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 11:45:14 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_multiplication.h"
#include "matrices.h"
#include <stddef.h>

static void	static_b_zero(void *ptr, size_t len)
{
	while (len-- > 0)
		*(unsigned char*)ptr++ = (unsigned char)0;
}

t_matrix_4	get_translation_matrix(double x, double y, double z)
{
	t_matrix_4	m;

	static_b_zero(&m, sizeof(t_matrix_4));
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
