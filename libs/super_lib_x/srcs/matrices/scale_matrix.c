/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:51:41 by vfries            #+#    #+#             */
/*   Updated: 2022/12/07 15:36:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "slx_utils.h"

/*						Scale matrix visualisation

[	scale_factor		0					0					0	]
[	0					scale_factor		0					0	]
[	0					0					scale_factor		0	]
[	0					0					0					1	]

																	*/
t_matrix_4	get_scale_matrix(double scale_factor)
{
	t_matrix_4	m;

	slx_bzero(&m, sizeof(t_matrix_4));
	m.m[0][0] = scale_factor;
	m.m[1][1] = scale_factor;
	m.m[2][2] = scale_factor;
	m.m[3][3] = 1.0;
	return (m);
}
