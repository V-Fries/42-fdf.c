/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:01:39 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 21:43:07 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_MATRIX_H
# define PROJECTION_MATRIX_H

# include "matrices.h"

typedef struct s_proj_matrix_data
{
	double	z_near;
	double	z_far;
	double	fov;
	double	aspect_ratio;
}	t_proj_matrix_data;

t_matrix_4	get_projection_matrix(t_proj_matrix_data *data);

#endif