/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:24 by vfries            #+#    #+#             */
/*   Updated: 2022/11/29 11:23:26 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_MATRICES_H
# define ROTATION_MATRICES_H

# include "matrices.h"

t_matrix_4	get_rotation_z_matrix(double rotation);
t_matrix_4	get_rotation_y_matrix(double rotation);
t_matrix_4	get_rotation_x_matrix(double rotation);

#endif
