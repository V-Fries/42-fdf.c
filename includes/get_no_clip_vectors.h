/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_clip_vectors.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 06:02:36 by vfries            #+#    #+#             */
/*   Updated: 2022/12/01 06:45:25 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NO_CLIP_VECTORS_H
# define GET_NO_CLIP_VECTORS_H

# include "fdf.h"
# include "ft_linked_list.h"

void	get_no_clip_vectors(t_matrix_4 *proj, t_list **vectors,
			t_vector_d start, t_vector_d end);

#endif
