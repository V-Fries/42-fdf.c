/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:41:23 by vfries            #+#    #+#             */
/*   Updated: 2022/11/27 20:55:46 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_3D_H
# define BRESENHAM_3D_H

# include "utils.h"
# include "ft_linked_list.h"

typedef struct s_abs_diff
{
	int	x;
	int	y;
	int	z;
}	t_abs_diff;

typedef struct s_incrementer
{
	int	x;
	int	y;
	int	z;
}	t_incrementer;

typedef struct s_bresenham_3d
{
	t_abs_diff		abs_diff;
	t_incrementer	increment;
}	t_bresenham_3d;

t_list	*bresenham_3d(t_3d_point start, t_3d_point end);

#endif
