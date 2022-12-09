/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:40:12 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:22:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include <stdint.h>

t_vector_d	matrix_times_vector(t_matrix_4 *m, t_vector_d *i)
{
	t_vector_d	new;

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

t_matrix_4	matrix_times_matrix(t_matrix_4 *m1, t_matrix_4 *m2)
{
	t_matrix_4	matrix;
	int8_t		y;
	int8_t		x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			matrix.m[x][y] = m1->m[x][0] * m2->m[0][y] + m1->m[x][1]
				* m2->m[1][y] + m1->m[x][2] * m2->m[2][y] + m1->m[x][3]
				* m2->m[3][y];
	}
	return (matrix);
}
