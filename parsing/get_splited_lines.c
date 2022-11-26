/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splited_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:04:17 by vfries            #+#    #+#             */
/*   Updated: 2022/11/26 21:12:00 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include <fcntl.h>
#include <stdlib.h>

static	t_list	*split_lines(t_list *lines, int *list_len)
{
	t_list	*cursor;
	char	*str;

	*list_len = 0;
	cursor = lines;
	while (cursor)
	{
		str = cursor->content;
		cursor->content = ft_split(cursor->content, ' ');
		if (cursor->content == NULL)
			return (cursor->content = str, ft_lstclear(&lines, &free), NULL);
		free(str);
		(*list_len)++;
		cursor = cursor->next;
	}
	return (lines);
}

t_list	*get_splited_lines(char *map_file, int *list_len)
{
	int		fd;
	char	*str;
	t_list	*lines;
	t_list	*lines_end;
	t_list	*new_node;

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
		str = get_next_line(fd);
	}
	return (split_lines(lines, list_len));
}
