/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:38:16 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 20:28:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

# define MAX_KEY 258

typedef struct s_keys
{
	int	keys[MAX_KEY];
	int	keys_pressed;
}	t_keys;

enum e_keys
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_E = 14,
	KEY_Q = 12,
	KEY_SPACE = 49,
	KEY_SHIFT = 257,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
};

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_img {
	void	*img;
	char	used_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_size;
	int		x_size;
}	t_img;

void		close_window(t_win *win);

int		put_img(t_img *img, t_win *win);
void	init_image(t_img *img, t_win *win, int y_len, int x_len);
void	put_pixel_on_img(t_img *img, int y, int x, int color);

#endif
