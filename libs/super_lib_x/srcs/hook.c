/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 05:07:29 by vfries            #+#    #+#             */
/*   Updated: 2022/12/10 14:18:21 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "window.h"
#include "mlx.h"

int	key_down(int key, t_keys *keys)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	keys->keys[key] = 1;
	keys->keys_pressed++;
	return (0);
}

int	key_up(int key, t_keys *keys)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	keys->keys[key] = 0;
	keys->keys_pressed--;
	return (0);
}

int	close_window_hook(t_win *win)
{
	close_window(win);
	return (0);
}

void	slx_hook(t_win *win, t_keys *keys)
{
	mlx_hook(win->win, ON_KEYDOWN, 2, &key_down, keys);
	mlx_hook(win->win, ON_KEYUP, 3, &key_up, keys);
	mlx_hook(win->win, ON_DESTROY, 0, &close_window_hook, win);
}
