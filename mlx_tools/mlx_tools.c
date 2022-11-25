/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:37:28 by vfries            #+#    #+#             */
/*   Updated: 2022/11/25 05:46:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"
#include "mlx.h"

int	close_window(t_win *win)
{
	return (mlx_destroy_window(win->mlx, win->win));
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
}

void	put_pixel_on_img(t_img *img, int y, int x, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
