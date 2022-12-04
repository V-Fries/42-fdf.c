/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:13:53 by vfries            #+#    #+#             */
/*   Updated: 2022/12/03 21:27:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "slx_utils.h"

/*						Translation matrix visualisation

[	1.0						0				0							0	]
[	0						1.0				0							0	]
[	0						0				1.0							0	]
[	x						y				z							1.0	]

																			*/
t_matrix_4	get_translation_matrix(double x, double y, double z)
{
	t_matrix_4	m;

	slx_bzero(&m, sizeof(t_matrix_4));
	m.m[0][0] = 1.0;
	m.m[1][1] = 1.0;
	m.m[2][2] = 1.0;
	m.m[3][3] = 1.0;
	m.m[3][0] = x;
	m.m[3][1] = y;
	m.m[3][2] = z;
	return (m);
}
