/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_fdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:57:35 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 18:58:09 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_FDF_H
# define CAMERA_FDF_H

# include "fdf.h"

void	move_camera_y_x(t_fdf *fdf, int key);
void	move_camera_up_down_rotation_z(t_fdf *fdf, int key);
void	move_camera_rotation(t_fdf *fdf, int key);

#endif