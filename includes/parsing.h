/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:46:31 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:24:20 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_linked_list.h"

double	parse_map(t_map *map, char *file_name);
void	get_map_a_and_m(t_map *map);
bool	fill_x(t_map *map, int y, t_list *lines);
void	free_map_2d_arr(t_vector_d **map_2d_arr);

#endif
