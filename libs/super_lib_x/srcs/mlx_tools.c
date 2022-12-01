/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:37:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/01 03:31:32 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"
#include "mlx.h"
#include <stdlib.h>

void	close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}

int	put_img(t_img *img, t_win *win)
{
	return (mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0));
}

void	init_image(t_img *img, t_win *win, int y_len, int x_len)
{
	img->img = mlx_new_image(win->mlx, x_len, y_len);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->y_size = y_len;
	img->x_size = x_len;
}

void	put_pixel_on_img(t_img *img, int y, int x, int color)
{
	char	*dst;

	if (y < 0 || y >= img->y_size || x < 0 || x >= img->x_size)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
