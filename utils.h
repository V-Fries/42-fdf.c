/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:09:08 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 23:34:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#define WINDOW_X 1400
#define WINDOW_Y 800

# include "mlx_tools.h"
# include "projection_matrix.h"

typedef struct s_fdf
{
	t_win				win;
	t_img				img;
	// t_3d_point			camera;
	// t_3d_point			orientation;
	// t_3d_point			screen;
	t_proj_matrix_data	proj_m_data;
}	t_fdf;

#endif
