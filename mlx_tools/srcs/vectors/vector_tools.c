/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:04:09 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:47:26 by vfries           ###   ########lyon.fr   */
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
	return (sqrt(vector_dot_product(v, v)));
}

t_vector_d	vector_normalise(t_vector_d *v)
{
	double		l;

	l = vector_length(v);
	if (l == 0.0)
		return (*v);
	return (create_vector(v->x / l, v->y / l, v->z / l, 1));
}

t_vector_d	vector_cross_product(t_vector_d *v1, t_vector_d *v2)
{
	return (create_vector(v1->y * v2->z - v1->z * v2->y,
			v1->z * v2->x - v1->x * v2->z,
			v1->x * v2->y - v1->y * v2->x,
			1));
}

t_vector_d	create_vector(double x, double y, double z, double w)
{
	t_vector_d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = w;
	return (new);
}
