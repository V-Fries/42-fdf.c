/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:11:25 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 21:12:35 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H

typedef struct s_2d_point_i
{
	int	x;
	int	y;
}	t_2d_point_i;

typedef struct s_3d_point_i
{
	int	x;
	int	y;
	int	z;
}	t_3d_point_i;

typedef struct s_3d_point_d
{
	double	x;
	double	y;
	double	z;
}	t_3d_point_d;

#endif