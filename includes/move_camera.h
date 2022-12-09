/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:57:35 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:24:27 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_CAMERA_H
# define MOVE_CAMERA_H

# include "fdf.h"

void	move_camera_y_x(t_fdf *fdf, int *keys);
void	move_camera_up_down_rotation_z(t_fdf *fdf, int *keys);
void	move_camera_rotation(t_fdf *fdf, int *keys);
void	move_camera_z(t_fdf *fdf, int *keys);

#endif
