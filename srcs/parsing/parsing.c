/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:45:25 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 06:00:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vector.h"
#include "ft_get_next_line.h"
#include "ft_string.h"
#include "ft_linked_list.h"
#include "ft_numbers.h"
#include "ft_io.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static t_list	*get_lines(int fd)
{
	char	*line;
	char	**splited_line;
	t_list	*new_elem;
	t_list	*lines;

	line = get_next_line(fd);
	lines = NULL;
	while (line)
	{
		splited_line = ft_split_set(line, " \n");
		free(line);
		if (splited_line == NULL)
			return (ft_lstclear(&lines, &ft_free_split), NULL);
		new_elem = ft_lstnew(splited_line);
		if (new_elem == NULL)
			return (ft_lstclear(&lines, &ft_free_split),
				ft_free_split(splited_line), NULL);
		ft_lstadd_front(&lines, new_elem);
		line = get_next_line(fd);
	}
	return (lines);
}

static void	free_map_o(t_vector_d **map_o)
{
	size_t	i;

	i = -1;
	while (map_o[++i])
		free(map_o[i]);
	free(map_o);
}

static void	get_map_o(t_map *map, t_list *lines)
{
	int	y;
	int	x;

	map->y_size = ft_lstsize(lines);
	map->o = malloc(sizeof(t_vector_d *) * map->y_size);
	if (map->o == NULL)
		return (ft_lstclear(&lines, &ft_free_split), (void)0);
	map->x_size = ft_split_size(lines->content);
	y = map->y_size;
	while (y-- > 0)
	{
		map->o[y] = malloc(sizeof(t_vector_d) * map->x_size);
		if (map->o[y] == NULL)
			return (ft_lstclear(&lines, &ft_free_split), free_map_o(map->o),
				map->o = NULL, (void)0);
		x = -1;
		while (++x < map->x_size)
		{
			if (((char **)lines->content)[x] == NULL)
				return (ft_lstclear(&lines, &ft_free_split), free_map_o(map->o),
					map->o = NULL, (void)0);
			map->o[y][x] = create_vector(x - map->x_size / 2,
					y - map->y_size / 2,
					-ft_atoll(((char **)lines->content)[x]), 1.0);
		}
		lines = ft_lst_get_next_free_current(lines, &ft_free_split);
	}
}

static double	get_map_m_return_highest_point(t_map *map)
{
	double	highest_point;
	int		y;
	int		x;

	highest_point = LLONG_MAX;
	map->m = malloc(sizeof(t_vector_d *) * map->y_size);
	if (map->m == NULL)
		return (free_map_o(map->o), ft_putstr("ERROR: Parsing failed.\n"),
			exit(1), 0);
	y = -1;
	while (++y < map->y_size)
	{
		map->m[y] = malloc(sizeof(t_vector_d) * map->x_size);
		if (map->m[y] == NULL)
			return (free_map_o(map->o), free_map_o(map->m),
				ft_putstr("ERROR: Parsing failed.\n"), exit(1), 0);
		x = -1;
		while (++x < map->x_size)
		{
			map->m[y][x] = map->o[y][x];
			if (map->o[y][x].z < highest_point)
				highest_point = map->o[y][x].z;
		}
	}
	return (-highest_point);
}


double	parse_map(t_map *map, char *file_name)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	get_map_o(map, get_lines(fd));
	close(fd);
	if (map->o == NULL)
		return (ft_putstr("ERROR: Parsing failed.\n"), exit(1), 0);
	return (get_map_m_return_highest_point(map));
}
