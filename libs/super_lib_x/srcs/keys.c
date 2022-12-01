/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 05:07:29 by vfries            #+#    #+#             */
/*   Updated: 2022/12/01 06:16:10 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

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
