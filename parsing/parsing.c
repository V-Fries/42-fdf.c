/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:45:54 by vfries            #+#    #+#             */
/*   Updated: 2022/11/26 21:30:41 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "get_next_line.h"
#include "get_splited_lines.h"
#include "ft_string.h"
#include <fcntl.h>


// static void	clean_splited_lines(t_list **splited_lines)
// {
// 	t_list	*current;

// 	current = *splited_lines;
// 	while (current)
// 	{
// 		if (current->content[0] == ',')

// 	}
// }

// t_map	*get_map(char *map_file)
// {
// 	t_map	*map;
// 	t_list	*splited_lines;
// 	int		list_len;

// 	splited_lines = get_splited_lines(map_file, &list_len);
// 	if (splited_lines == NULL)
// 		return (NULL);
// 	clean_splited_lines(&list_len);
// 	map = init_map(*splited_lines);
// }


t_list	*get_lines(char *map_file, int *list_len)
{
	int		fd;
	char	*str;
	t_list	*lines;
	t_list	*lines_end;
	t_list	*new_node;

	*list_len = 0;
	lines = NULL;
	lines_end = NULL;
	fd = open(map_file, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (close(fd), NULL);
	while (str)
	{
		new_node = ft_lstnew(str);
		if (new_node == NULL)
			return (close(fd), ft_lstclear(&lines, &free), free(str), NULL);
		ft_lstadd_back(&lines_end, new_node);
		if (lines == NULL)
			lines = lines_end;
		(*list_len)++;
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

t_map	*init_map(int nb_of_lines)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map.map
}

t_map	*get_map(char *map_file)
{
	t_list	*lines;
	int		nb_of_lines;

	lines = get_lines(map_file, &nb_of_lines);
	if (lines == NULL)
		return (NULL);

}
