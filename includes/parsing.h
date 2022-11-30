/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:46:31 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 20:20:56 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_linked_list.h"

typedef struct s_map
{
	int	**map;
	int	**color;
}	t_map;

t_list	*get_splited_lines(char *map_file, int *list_len);


#endif
