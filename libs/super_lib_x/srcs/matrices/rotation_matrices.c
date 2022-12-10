/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:03:17 by vfries            #+#    #+#             */
/*   Updated: 2022/12/10 19:16:21 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "slx_utils.h"
#include <math.h>

/*						Rotation X matrix visualisation

[	1				0						0							0	]
[	0				cos(rotation * 0.5f)	sin(rotation * 0.5f)		0	]
[	0				-sin(rotation * 0.5f)	cos(rotation * 0.5f)		0	]
[	0				0						0							1	]

																			*/
t_matrix_4	get_rotation_x_matrix(double theta)
{
	t_matrix_4	m;

	slx_bzero(&m, sizeof(t_matrix_4));
	m.m[0][0] = 1.0;
	m.m[1][1] = cos(theta * 0.5);
	m.m[1][2] = sin(theta * 0.5);
	m.m[2][1] = -m.m[1][2];
	m.m[2][2] = m.m[1][1];
	m.m[3][3] = 1.0;
	return (m);
}

/*						Rotation Y matrix visualisation

[	cos(rotation)			0				sin(rotation)				0	]
[	0						1				0							0	]
[	-sin(rotation)			0				cos(rotation)				0	]
[	0						0				0							1	]

																			*/
t_matrix_4	get_rotation_y_matrix(double theta)
{
	t_matrix_4	m;

	slx_bzero(&m, sizeof(t_matrix_4));
	m.m[0][0] = cos(theta);
	m.m[0][2] = sin(theta);
	m.m[2][0] = -m.m[0][2];
	m.m[1][1] = 1.0;
	m.m[2][2] = m.m[0][0];
	m.m[3][3] = 1.0;
	return (m);
}

/*						Rotation Z matrix visualisation

[	cos(rotation)			sin(rotation)	0							0	]
[	-sin(rotation)			cos(rotation)	0							0	]
[	0						0				1							0	]
[	0						0				0							1	]

																			*/
t_matrix_4	get_rotation_z_matrix(double theta)
{
	t_matrix_4	m;

	slx_bzero(&m, sizeof(t_matrix_4));
	m.m[0][0] = cos(theta);
	m.m[0][1] = sin(theta);
	m.m[1][0] = -m.m[0][1];
	m.m[1][1] = m.m[0][0];
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}
