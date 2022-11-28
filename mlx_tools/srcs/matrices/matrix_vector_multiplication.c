/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multiplication.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:31:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 21:44:19 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"
#include "matrices.h"

void	matrix_vector_multiplication(t_3d_point_d *i, t_3d_point_d *o,
	t_matrix_4 *m)
{
	double	w;

	o->x = i->x * m->m[0][0] + i->y * m->m[1][0] + i->z * m->m[2][0]
		+ m->m[3][0];
	o->y = i->x * m->m[0][1] + i->y * m->m[1][1] + i->z * m->m[2][1]
		+ m->m[3][1];
	o->z = i->x * m->m[0][2] + i->y * m->m[1][2] + i->z * m->m[2][2]
		+ m->m[3][2];
	w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}
