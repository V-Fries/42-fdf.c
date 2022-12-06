/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:38:16 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 18:34:52 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_img {
	void	*img;
	double	**depth;
	char	used_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_size;
	int		x_size;
}	t_img;

void	close_window(t_win *win);

int		put_img(t_img *img, t_win *win);
void	init_image(t_img *img, t_win *win, int y_len, int x_len);
void	reset_img(t_img *img, int background_color);
void	put_pixel_on_img(t_img *img, int y, int x, int color, double depth);

#endif
