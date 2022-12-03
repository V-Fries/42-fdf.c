/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:45:25 by vfries            #+#    #+#             */
/*   Updated: 2022/12/03 03:49:19 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vector.h"
#include "ft_io.h"
#include "ft_char.h"
#include "ft_get_next_line.h"
#include "ft_string.h"
#include "ft_linked_list.h"
#include "ft_mem.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

static t_vector_d	**get_map_o(t_map *map, t_list *lines)
{
	t_vector_d	**ret;
	size_t		y;

	if (lines == NULL)
		return (NULL);
	map->y_size = ft_lstsize(lines);
	ret = ft_calloc(sizeof(t_vector_d *), map->y_size);
	if (ret == NULL)
		return (NULL);
	map->x_size = ft_split_size(lines->content);
	y = map->y_size;
	while (y--)
	{
		if (lines == NULL)
			return (ft_lstclear(&lines, &ft_free_split), free_map_o(ret), NULL);
		ret[y] = malloc(sizeof(t_vector_d) * map->x_size);
		if (ret[y] == NULL)
			return (ft_lstclear(&lines, &ft_free_split),
				free_map_o(ret), NULL);
		init_ret_y(ret + y, lines);
		if (ret[y][0].x < 0)
			return (ft_lstclear(&lines, &ft_free_split),
				free_map_o(ret), NULL);
		lines = ft_lst_get_next_free_current(lines, &ft_free_split);
	}
	if (lines != NULL)
		return (ft_lstclear(&lines, &ft_free_split), free_map_o(ret), NULL);
	return (lines);
}

int	parse_map(t_map *map, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	map->o = get_map_o(get_lines(fd));
	close(fd);
	if (map->o == NULL)
		return (ft_putstr("ERROR: Parsing failed.\n"), 0);
}
