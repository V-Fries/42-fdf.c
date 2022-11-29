/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_at_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 06:57:27 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:29:41 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "vector.h"

typedef struct s_get_point_at_matrix_input
{
	t_vector_d	*pos;
	t_vector_d	*target;
	t_vector_d	*up;
}	t_get_point_at_matrix_input;

static void	init_get_point_at_matrix(t_vector_d *new_forward,
	t_vector_d *new_up, t_vector_d *new_right, t_get_point_at_matrix_input data)
{
	t_vector_d	a;

	*new_forward = vector_sub(data.target, data.pos);
	*new_forward = vector_normalise(new_forward);

	a = vector_multiply(new_forward,
			vector_dot_product(data.up, new_forward));
	*new_up = vector_sub(data.up, &a);
	*new_up = vector_normalise(new_up);

	*new_right = vector_cross_product(new_up, new_forward);
}

static t_get_point_at_matrix_input	create_data(t_vector_d *pos,
	t_vector_d *target, t_vector_d *up)
{
	t_get_point_at_matrix_input	data;

	data.pos = pos;
	data.target = target;
	data.up = up;
	return (data);
}

t_matrix_4	get_point_at_matrix(t_vector_d *pos, t_vector_d *target,
		t_vector_d *up)
{
	t_vector_d	new_forward;
	t_vector_d	new_up;
	t_vector_d	new_right;
	t_matrix_4	matrix;

	init_get_point_at_matrix(&new_forward, &new_up, &new_right,
		create_data(pos, target, up));
	matrix.m[0][0] = new_right.x;
	matrix.m[0][1] = new_right.y;
	matrix.m[0][2] = new_right.z;
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = new_up.x;
	matrix.m[1][1] = new_up.y;
	matrix.m[1][2] = new_up.z;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = new_forward.x;
	matrix.m[2][1] = new_forward.y;
	matrix.m[2][2] = new_forward.z;
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = pos->x;
	matrix.m[3][1] = pos->y;
	matrix.m[3][2] = pos->z;
	matrix.m[3][3] = 1.0f;
	return (matrix);
}
