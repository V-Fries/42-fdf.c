/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:01:16 by vfries            #+#    #+#             */
/*   Updated: 2022/12/10 14:20:11 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "render_frame.h"

void	start_fdf(t_fdf *fdf)
{
	slx_hook(&fdf->win, &fdf->keys);
	mlx_loop_hook(fdf->win.mlx, &render_frame, fdf);
	mlx_loop(fdf->win.mlx);
}
