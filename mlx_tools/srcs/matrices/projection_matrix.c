/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:55:44 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 00:11:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "projection_matrix.h"
#include <math.h>
#include <stddef.h>

static void	static_b_zero(void *ptr, size_t len)
{
	while (len-- > 0)
		*(unsigned char*)ptr++ = (unsigned char)0;
}

/*						Projection matrix visualisation

[	(h/w)*(1/tan(fov/2))	0				0							0	]
[	0						(1/tan(fov/2))	0							0	]
[	0						0				zfar/(zfar-znear)			1	]
[	0						0				-(zfar/(zfar-znear))*znear	0	]

																			*/
t_matrix_4	get_projection_matrix(t_proj_matrix_data *data)
{
	t_matrix_4	m;
	double	fov_rad;
	double	z_far_z_near;

	fov_rad = 1.0f / tanf(data->fov * 0.5f / 180.0f * M_PI);
	z_far_z_near = data->z_far / (data->z_far - data->z_near);
	static_b_zero(&m, sizeof(t_matrix_4));
	m.m[0][0] = data->aspect_ratio * fov_rad;
	m.m[1][1] = fov_rad;
	m.m[2][2] = z_far_z_near;
	m.m[3][2] = (-z_far_z_near) * data->z_near;
	m.m[2][3] = 1.0f;
	m.m[3][3] = 0.0f;
	return (m);
}
