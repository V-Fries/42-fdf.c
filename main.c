/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/11/24 14:32:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "mlx.h"

#define WINDOW_X 1080
#define WINDOW_Y 1080

typedef struct s_window
{
	void	*mlx;
	void	*window;
}	t_window;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	put_pixel_on_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_image(t_img *img, t_window *window, int window_x, int window_y)
{
	img->img = mlx_new_image(window->mlx, window_x, window_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	deal_key(int key, void *param)
{
	static int	color = 0xFFFFFF;
	t_window	*window;
	t_img		img;

	(void)key;
	window = (t_window *)param;
	init_image(&img, window, WINDOW_X, WINDOW_Y);
	for (int y = 0; y < 500; y++)
		for (int x = 0; x < 500; x++)
			put_pixel_on_img(&img, x, y, color);
	mlx_put_image_to_window(window->mlx, window->window, img.img, 0, 0);
	color += 100000;
	return (0);
}

int	main(void)
{
	t_window	window;

	window.mlx = mlx_init();
	window.window = mlx_new_window(window.mlx, WINDOW_X, WINDOW_Y, "fdf");
	mlx_key_hook(window.window, &deal_key, &window);
	mlx_loop(window.mlx);
}
