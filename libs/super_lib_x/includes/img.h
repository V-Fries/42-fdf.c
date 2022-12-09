/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:38:16 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 18:31:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include "window.h"

typedef struct s_img
{
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

typedef struct s_pixel
{
	int		x;
	int		y;
	int		color;
	double	depth;
}	t_pixel;

int		put_img(t_img *img, t_win *win);
void	init_image(t_img *img, t_win *win, int y_len, int x_len);
void	reset_img(t_img *img, int background_color);
void	put_pixel_on_img(t_img *img, t_pixel pixel);
t_pixel	create_t_pixel(int x, int y, int color, double depth);

#endif
