/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:03:17 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 00:25:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include <stddef.h>
#include <math.h>

static void	static_b_zero(void *ptr, size_t len)
{
	while (len-- > 0)
		*(unsigned char*)ptr++ = (unsigned char)0;
}

/*						Rotation Z matrix visualisation

[	cosf(rotation)			sinf(rotation)	0							0	]
[	-sinf(rotation)			cosf(rotation)	0							0	]
[	0						0				1							0	]
[	0						0				0							1	]

																			*/
t_matrix_4	get_rotation_z_matrix(double rotation)
{
	t_matrix_4	m;

	static_b_zero(&m, sizeof(t_matrix_4));
	m.m[0][0] = cosf(rotation);
	m.m[0][1] = sinf(rotation);
	m.m[1][0] = -m.m[0][1];
	m.m[1][1] = m.m[0][0];
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

/*						Rotation X matrix visualisation

[	1				0						0							0	]
[	0				cosf(rotation * 0.5f)	sinf(rotation * 0.5f)		0	]
[	0				-sinf(rotation * 0.5f)	cosf(rotation * 0.5f)		0	]
[	0				0						0							1	]

																			*/
t_matrix_4	get_rotation_x_matrix(double rotation)
{
	t_matrix_4	m;

	static_b_zero(&m, sizeof(t_matrix_4));
	m.m[0][0] = 1;
	m.m[1][1] = cosf(rotation * 0.5f);
	m.m[1][2] = sinf(rotation * 0.5f);
	m.m[2][1] = -m.m[1][2];
	m.m[2][2] = m.m[1][1];
	m.m[3][3] = 1;
	return (m);
}
