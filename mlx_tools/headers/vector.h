/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:51:47 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 07:19:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector_i
{
	int	x;
	int	y;
	int	z;
}	t_vector_i;

typedef struct s_vector_d
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector_d;

t_vector_d	vector_add(t_vector_d *a, t_vector_d *b);
t_vector_d	vector_sub(t_vector_d *a, t_vector_d *b);
t_vector_d	vector_multiply(t_vector_d *a, double k);
t_vector_d	vector_divide(t_vector_d *a, double k);

double		vector_dot_product(t_vector_d *v1, t_vector_d *v2);
double		vector_length(t_vector_d *v);
t_vector_d	vector_normalise(t_vector_d *v);
t_vector_d	vector_cross_product(t_vector_d *v1, t_vector_d *v2);

#endif
