/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:37:28 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:19:45 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include "mlx.h"
#include <limits.h>
#include <stdlib.h>

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

void	put_pixel_on_img(t_img *img, t_pixel pixel)
{
	char	*dst;

	if (img->depth[pixel.y][pixel.x] < pixel.depth)
		return ;
	img->depth[pixel.y][pixel.x] = pixel.depth;
	dst = img->addr
		+ (pixel.y * img->line_length + pixel.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel.color;
}

t_pixel	create_t_pixel(int x, int y, int color, double depth)
{
	t_pixel	new;

	new.x = x;
	new.y = y;
	new.color = color;
	new.depth = depth;
	return (new);
}
