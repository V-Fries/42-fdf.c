/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_clip_vectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:47:24 by vfries            #+#    #+#             */
/*   Updated: 2022/12/01 06:39:37 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"
#include "fdf.h"
#include <stdlib.h>

static t_vector_d	*get_two_vec(t_matrix_4 m, t_vector_d a, t_vector_d b)
{
	t_vector_d	*ret;

	ret = malloc(sizeof(t_vector_d) * 2);
	if (ret == NULL)
		return (NULL);
	ret[0] = apply_projection_matrix(&m, &a, WINDOW_X, WINDOW_Y);
	ret[1] = apply_projection_matrix(&m, &b, WINDOW_X, WINDOW_Y);
	return (ret);
}

void	get_no_clip_vectors(t_fdf *fdf, t_list **vectors,
		t_vector_d start, t_vector_d end)
{

}
