/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:04:09 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 07:19:22 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double	vector_dot_product(t_vector_d *v1, t_vector_d *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double	vector_length(t_vector_d *v)
{
	return sqrt(vector_dot_product(v, v));
}

t_vector_d	vector_normalise(t_vector_d *v)
{
	t_vector_d	new;
	double		l;

	l = vector_length(v);
	new.x = v->x / l;
	new.y = v->y / l;
	new.z = v->z / l;
	new.w = 1;
	return (new);
}

t_vector_d	vector_cross_product(t_vector_d *v1, t_vector_d *v2)
{
	t_vector_d new;

	new.x = v1->y * v2->z - v1->z * v2->y;
	new.y = v1->z * v2->x - v1->x * v2->z;
	new.z = v1->x * v2->y - v1->y * v2->x;
	new.w = 1;
	return new;
}
