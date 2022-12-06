/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:01:16 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 01:18:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "render_frame.h"
#include "keys.h"

void	start_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->win.win, ON_KEYDOWN, 2, &key_down, &fdf->keys);
	mlx_hook(fdf->win.win, ON_KEYUP, 3, &key_up, &fdf->keys);
	mlx_loop_hook(fdf->win.mlx, &render_frame, fdf);
	mlx_loop(fdf->win.mlx);
}
