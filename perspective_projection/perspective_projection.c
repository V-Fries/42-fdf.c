/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:48:17 by vfries            #+#    #+#             */
/*   Updated: 2022/11/28 00:48:00 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "utils.h"

typedef struct s_doubles
{
	double	x;
	double	y;
	double	z;
}	t_doubles;

typedef struct s_pre_calculation
{
	t_doubles	sin_o;
	t_doubles	cos_o;
	t_doubles	a_minus_c;
	double		patern_1;
	double		patern_2;
	double		patern_3;
}	t_pre_calculation;

// Does calculations that are repeated multiple times in the equation
static void	pre_calculate(register t_pre_calculation *pre,
	t_3d_point a, t_3d_point c, t_3d_point o)
{
	pre->sin_o.x = sin(o.x);
	pre->sin_o.y = sin(o.y);
	pre->sin_o.z = sin(o.z);
	pre->cos_o.x = cos(o.x);
	pre->cos_o.y = cos(o.y);
	pre->cos_o.z = cos(o.z);
	pre->a_minus_c.x = a.x - c.x;
	pre->a_minus_c.y = a.y - c.y;
	pre->a_minus_c.z = a.z - c.z;
	pre->patern_1 = pre->sin_o.z * pre->a_minus_c.y + pre->cos_o.z
		* pre->a_minus_c.x;
	pre->patern_2 = pre->cos_o.y * pre->a_minus_c.z + pre->sin_o.y
		* pre->patern_1;
	pre->patern_3 = pre->cos_o.z * pre->a_minus_c.y - pre->sin_o.z
		* pre->a_minus_c.x;
}

// https://en.wikipedia.org/wiki/3D_projection
// https://wikimedia.org/api/rest_v1/media/math/render/svg/
// d6e81e05bfcd4cd41612c318806d4a9e14cf591c
// a == the 3D position of a point A that is to be projected.
// c == the 3D position of a point C representing the camera.
// o == The orientation of the camera (represented by Tait–Bryan angles).
static t_3d_point	get_d(t_3d_point a, t_3d_point c, t_3d_point o)
{
	t_3d_point			d;
	t_pre_calculation	pre;

	pre_calculate(&pre, a, c, o);
	d.x = pre.cos_o.y * pre.patern_1 - pre.sin_o.y * pre.a_minus_c.z;
	d.y = pre.sin_o.x * pre.patern_2 + pre.cos_o.x * pre.patern_3;
	d.z = pre.cos_o.x * pre.patern_2 + pre.sin_o.x * pre.patern_3;
	return (d);
}

// https://en.wikipedia.org/wiki/3D_projection
// a == The 3D position of a point A that is to be projected.
// c == The 3D position of a point C representing the camera.
// o == The orientation of the camera (represented by Tait–Bryan angles).
// e == The display surface's position relative to the camera pinhole C.
t_2d_point	*perspective_projection(t_3d_point a, t_3d_point c, t_3d_point o,
	t_3d_point e)
{
	t_3d_point	d;
	t_2d_point	*b;
	double		pre_calculate;

	b = malloc(sizeof(t_2d_point));
	if (b == NULL)
		return (NULL);
	d = get_d(a, c, o);
	pre_calculate = (double)e.z / (double)d.z;
	b->x = pre_calculate * (double)d.x + e.x;
	b->y = pre_calculate * (double)d.y + e.y;
	return (b);
}
