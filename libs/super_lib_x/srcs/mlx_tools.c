/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:37:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 18:54:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"
#include "mlx.h"
#include "slx_utils.h"
#include <stdlib.h>
#include <limits.h>

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
	int	i;
	int	x;

	img->depth = malloc(sizeof(*img->depth) * y_len);
	if (img->depth == NULL)
		return (img->img = NULL, img->addr = NULL, (void)0);
	i = -1;
	while (++i < y_len)
	{
		img->depth[i] = malloc(sizeof(**img->depth) * x_len);
		x = -1;
		while (++x < x_len)
			img->depth[i][x] = ULONG_MAX;
	}
	img->img = mlx_new_image(win->mlx, x_len, y_len);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->y_size = y_len;
	img->x_size = x_len;
}

void	reset_img(t_img *img, int background_color)
{
	char	*dst;
	int		y;
	int		x;

	y = -1;
	while (++y < img->y_size)
	{
		x = -1;
		while (++x < img->x_size)
		{
			img->depth[y][x] = ULONG_MAX;
			dst = img->addr + (y * img->line_length + x
					* (img->bits_per_pixel / 8));
			*(unsigned int *)dst = background_color;
		}
	}
}

void	put_pixel_on_img(t_img *img, int y, int x, int color, double depth)
{
	char	*dst;

	if (img->depth[y][x] < depth)
		return ;
	img->depth[y][x] = depth;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
