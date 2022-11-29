/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:55:12 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 04:54:12 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector_d	vector_add(t_vector_d *a, t_vector_d *b)
{
	t_vector_d	new;

	new.x = a->x + b->x;
	new.y = a->y + b->y;
	new.z = a->z + b->z;
	new.w = 1;
	return (new);
}

t_vector_d	vector_sub(t_vector_d *a, t_vector_d *b)
{
	t_vector_d	new;

	new.x = a->x - b->x;
	new.y = a->y - b->y;
	new.z = a->z - b->z;
	new.w = 1;
	return (new);
}

t_vector_d	vector_multiply(t_vector_d *a, double k)
{
	t_vector_d	new;

	new.x = a->x * k;
	new.y = a->y * k;
	new.z = a->z * k;
	new.w = 1;
	return (new);
}

t_vector_d	vector_divide(t_vector_d *a, double k)
{
	t_vector_d	new;

	if (k == 0)
		return (*a);
	new.x = a->x / k;
	new.y = a->y / k;
	new.z = a->z / k;
	new.w = 1;
	return (new);
}
