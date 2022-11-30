/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:51:26 by vfries            #+#    #+#             */
/*   Updated: 2022/11/30 18:52:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	mlx_tools_b_zero(void *ptr, size_t len)
{
	while (len-- > 0)
		*(unsigned char *)ptr++ = (unsigned char)0;
}
