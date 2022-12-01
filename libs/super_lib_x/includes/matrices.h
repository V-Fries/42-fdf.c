/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:43:10 by vfries            #+#    #+#             */
/*   Updated: 2022/12/01 06:28:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "vector.h"

typedef struct s_matrix_4
{
	double	m[4][4];
}	t_matrix_4;

typedef struct s_proj_m
{
	t_matrix_4	m;
	double		z_near;
	double		z_far;
	double		fov;
	double		aspect_ratio;
}	t_proj_m;

typedef struct s_rot_m
{
	t_matrix_4	m;
	double		rot;
}	t_rot_m;

typedef struct s_trans_m
{
	t_matrix_4	m;
	double		x;
	double		y;
	double		z;
}	t_trans_m;

typedef struct s_matrices
{
	t_proj_m	proj;
	t_rot_m		rot_z;
	t_rot_m		rot_x;
	t_rot_m		rot_y;
	t_trans_m	trans;
	t_matrix_4	world;
}	t_matrices;

t_vector_d	matrix_times_vector(t_matrix_4 *m, t_vector_d *i);
t_matrix_4	matrix_times_matrix(t_matrix_4 *m1, t_matrix_4 *m2);

t_matrix_4	get_projection_matrix(t_proj_m *data);
t_vector_d	apply_projection_matrix(t_matrix_4 *m, t_vector_d *v,
				double window_x, double window_y);

t_matrix_4	get_rotation_z_matrix(double rotation);
t_matrix_4	get_rotation_y_matrix(double rotation);
t_matrix_4	get_rotation_x_matrix(double rotation);

t_matrix_4	get_translation_matrix(double x, double y, double z);
t_matrix_4	get_world_matrix(t_matrix_4 *rot_z, t_matrix_4 *rot_x,
				t_matrix_4 *rot_y, t_matrix_4 *trans);
void		update_translation_matrix(t_matrices *mats);
void		update_rot_z_matrix(t_matrices *mats);
void		update_rot_x_matrix(t_matrices *mats);
void		update_rot_y_matrix(t_matrices *mats);

#endif
