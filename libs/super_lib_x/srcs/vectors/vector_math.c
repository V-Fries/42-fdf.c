/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:55:12 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 10:42:51 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector_d	vector_add(t_vector_d *a, t_vector_d *b)
{
	return (create_vector(a->x + b->x, a->y + b->y, a->z + b->z, 1));
}

t_vector_d	vector_sub(t_vector_d *a, t_vector_d *b)
{
	return (create_vector(a->x - b->x, a->y - b->y, a->z - b->z, 1));
}

t_vector_d	vector_multiply(t_vector_d *a, double k)
{
	return (create_vector(a->x * k, a->y * k, a->z * k, 1));
}

t_vector_d	vector_divide(t_vector_d *a, double k)
{
	if (k == 0)
		return (*a);
	return (create_vector(a->x / k, a->y / k, a->z / k, 1));
}
