/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:09:08 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 16:30:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_tools.h"
# include "matrices.h"
# include "keys.h"
# include <stdbool.h>

# define WINDOW_X 1800
# define WINDOW_Y 1200

# define VIEW_POINTS 1
# define VIEW_LINES 0

typedef struct s_map
{
	int			**i_map;
	t_vector_d	**o;
	t_vector_d	**a;
	t_vector_d	**m;
	int			highest_point;
	int			y_size;
	int			x_size;
}	t_map;

typedef struct s_fdf
{
	t_win		win;
	t_img		img;
	t_keys		keys;
	char		view_mode;
	bool		colors;
	double		cam_speed;
	double		cam_rot_speed;
	t_map		map;
	t_matrices	mats;
}	t_fdf;

#endif
