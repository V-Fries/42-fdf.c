/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:09:36 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:17:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_string.h"
#include "ft_linked_list.h"
#include "ft_numbers.h"
#include <stdlib.h>

void	free_map_2d_arr(t_vector_d **map_2d_arr)
{
	size_t	i;

	i = -1;
	while (map_2d_arr[++i])
		free(map_2d_arr[i]);
	free(map_2d_arr);
}

bool	fill_x(t_map *map, int y, t_list *lines)
{
	int	x;

	x = -1;
	while (++x < map->x_size)
	{
		if (((char **)lines->content)[x] == NULL)
			return (ft_lstclear(&lines, &ft_free_split),
				free_map_2d_arr(map->o), map->o = NULL, false);
		map->o[y][x] = create_vector(x - map->x_size / 2,
				y - map->y_size / 2,
				-ft_atoll(((char **)lines->content)[x]), 1.0);
	}
	return (true);
}

void	get_map_a_and_m(t_map *map)
{
	int	x;
	int	y;

	map->a = malloc(sizeof(t_vector_d *) * map->y_size);
	map->m = malloc(sizeof(t_vector_d *) * map->y_size);
	if (map->a == NULL || map->m == NULL)
		return (free_map_2d_arr(map->o), free(map->a), free(map->m),
			map->o = NULL, (void)0);
	y = -1;
	while (++y < map->y_size)
	{
		map->a[y] = malloc(sizeof(t_vector_d) * map->x_size);
		map->m[y] = malloc(sizeof(t_vector_d) * map->x_size);
		if (map->a[y] == NULL || map->m[y] == NULL)
			return (free_map_2d_arr(map->o), free_map_2d_arr(map->a),
				free_map_2d_arr(map->m), map->o = NULL, (void)0);
		x = -1;
		while (++x < map->x_size)
			map->a[y][x] = map->o[y][x];
	}
}
