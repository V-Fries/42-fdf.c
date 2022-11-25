/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:38:16 by vfries            #+#    #+#             */
/*   Updated: 2022/11/25 07:36:39 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

enum e_keys
{
	ESC = 53
};

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

int		close_window(t_win *win);

int		put_img(t_img *img, t_win *win);
void	init_image(t_img *img, t_win *win, int y_len, int x_len);
void	put_pixel_on_img(t_img *img, int y, int x, int color);


#endif
