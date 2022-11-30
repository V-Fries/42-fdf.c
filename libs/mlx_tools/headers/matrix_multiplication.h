/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:14:25 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 02:45:18 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_MULTIPLICATION_H
# define MATRIX_MULTIPLICATION_H

# include "matrices.h"
# include "vector.h"

t_vector_d	matrix_times_vector(t_matrix_4 *m, t_vector_d *i);
t_matrix_4	matrix_times_matrix(t_matrix_4 *m1, t_matrix_4 *m2);

#endif
