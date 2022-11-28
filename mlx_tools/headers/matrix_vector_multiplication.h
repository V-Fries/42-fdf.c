/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multiplication.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:14:25 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 23:15:09 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_VECTOR_MULTIPLICATION_H
# define MATRIX_VECTOR_MULTIPLICATION_H

# include "matrices.h"
# include "points.h"

void	matrix_vector_multiplication(t_3d_point_d *i, t_3d_point_d *o,
	t_matrix_4 *m);

#endif