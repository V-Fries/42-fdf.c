/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:43:10 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 19:28:34 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "vector.h"

typedef struct s_matrix_4
{
	double	m[4][4];
}	t_matrix_4;

typedef struct s_proj_matrix_data
{
	double	z_near;
	double	z_far;
	double	fov;
	double	aspect_ratio;
}	t_proj_matrix_data;

typedef struct s_matrices
{
	t_matrix_4			proj;
	t_proj_matrix_data	proj_m_data;
	t_matrix_4			rot_z;
	double				rot_z_rot;
	t_matrix_4			rot_x;
	double				rot_x_rot;
	t_matrix_4			rot_y;
	t_matrix_4			trans;
	t_matrix_4			world;
}	t_matrices;

t_vector_d	matrix_times_vector(t_matrix_4 *m, t_vector_d *i);
t_matrix_4	matrix_times_matrix(t_matrix_4 *m1, t_matrix_4 *m2);


t_matrix_4	get_projection_matrix(t_proj_matrix_data *data);

t_matrix_4	get_rotation_z_matrix(double rotation);
t_matrix_4	get_rotation_y_matrix(double rotation);
t_matrix_4	get_rotation_x_matrix(double rotation);

t_matrix_4	get_translation_matrix(double x, double y, double z);
t_matrix_4	get_world_matrix(t_matrix_4 *rot_z, t_matrix_4 *rot_x,
				t_matrix_4 *rot_y, t_matrix_4 *trans);
void		update_rot_z_matrix(t_matrices *mats);
void		update_rot_x_matrix(t_matrices *mats);

#endif
