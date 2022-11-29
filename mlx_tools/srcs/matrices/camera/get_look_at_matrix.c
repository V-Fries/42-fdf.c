/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_look_at_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:15:15 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:38:23 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
	This function reverses the point_at_m matrix which result in a
		look at matrix
*/
t_matrix_4	get_look_at_matrix(t_matrix_4 *point_at_m)
{
	t_matrix_4	new;

	new.m[0][0] = point_at_m->m[0][0];
	new.m[0][1] = point_at_m->m[1][0];
	new.m[0][2] = point_at_m->m[2][0];
	new.m[0][3] = 0.0f;
	new.m[1][0] = point_at_m->m[0][1];
	new.m[1][1] = point_at_m->m[1][1];
	new.m[1][2] = point_at_m->m[2][1];
	new.m[1][3] = 0.0f;
	new.m[2][0] = point_at_m->m[0][2];
	new.m[2][1] = point_at_m->m[1][2];
	new.m[2][2] = point_at_m->m[2][2];
	new.m[2][3] = 0.0f;
	new.m[3][0] = -(point_at_m->m[3][0] * new.m[0][0] + point_at_m->m[3][1]
			* new.m[1][0] + point_at_m->m[3][2] * new.m[2][0]);
	new.m[3][1] = -(point_at_m->m[3][0] * new.m[0][1] + point_at_m->m[3][1]
			* new.m[1][1] + point_at_m->m[3][2] * new.m[2][1]);
	new.m[3][2] = -(point_at_m->m[3][0] * new.m[0][2] + point_at_m->m[3][1]
			* new.m[1][2] + point_at_m->m[3][2] * new.m[2][2]);
	new.m[3][3] = 1.0f;
	return (new);
}
