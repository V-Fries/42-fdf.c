/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:40:12 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 02:44:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrices.h"

t_vector_d	matrix_times_vector(t_matrix_4 *m, t_vector_d *i)
{
	t_vector_d new;

	new.x = i->x * m->m[0][0] + i->y * m->m[1][0] + i->z * m->m[2][0]
		+ i->w * m->m[3][0];
	new.y = i->x * m->m[0][1] + i->y * m->m[1][1] + i->z * m->m[2][1]
		+ i->w * m->m[3][1];
	new.z = i->x * m->m[0][2] + i->y * m->m[1][2] + i->z * m->m[2][2]
		+ i->w * m->m[3][2];
	new.w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3]
		+ i->w * m->m[3][3];
	return (new);
}

t_matrix_4 matrix_times_matrix(t_matrix_4 *m1, t_matrix_4 *m2)
{
	t_matrix_4 matrix;
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			matrix.m[r][c] = m1->m[r][0] * m2->m[0][c] + m1->m[r][1]
				* m2->m[1][c] + m1->m[r][2] * m2->m[2][c] + m1->m[r][3]
				* m2->m[3][c];
	return matrix;
}
