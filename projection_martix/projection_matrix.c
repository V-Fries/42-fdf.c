/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:55:44 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 14:15:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_mem.h"
#include <math.h>

/*							Projection matrix visualisation

[(h/w)*(1/tan(fov/2))	0				0					0							]
[0						(1/tan(fov/2))	0					0							]
[0						0				zfar/(zfar-znear)	-(zfar/(zfar-znear))*znear	]
[0						0				1					0							]

																			*/
t_matrix_4	get_projection_matrix(double fov, double aspect, float znear,
	float zfar)
{
	t_matrix_4	matrix;
	double		pre_calculate_fov;
	double		pre_calculate_znear_zfar;

	pre_calculate_fov = (1.0 / tan(fov / 2.0));
	pre_calculate_znear_zfar = zfar / (zfar - znear);
	ft_memset(&matrix, 0, sizeof(t_matrix_4));
	matrix.mat[0][0] = aspect * pre_calculate_fov;
	matrix.mat[1][1] = pre_calculate_fov;
	matrix.mat[2][2] = pre_calculate_znear_zfar;
	matrix.mat[2][3] = (-pre_calculate_znear_zfar) * znear;
	matrix.mat[3][2] = 1.0;
	return (matrix);
}
