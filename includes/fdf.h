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

# define WINDOW_X 1400
# define WINDOW_Y 800

# include "mlx_tools.h"
# include "matrices.h"
# include "camera.h"

typedef struct s_map
{
	int			**i_map;
	t_vector_d	**o_v_map;
	t_vector_d	**m_v_map;
	int			y_size;
	int			x_size;
}	t_map;

typedef struct s_fdf
{
	t_win		win;
	t_img		img;
	t_keys		keys;
	t_cam		cam;
	t_map		map;
	t_matrices	mats;
}	t_fdf;

#endif
