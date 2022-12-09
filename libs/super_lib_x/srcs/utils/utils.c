/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:51:26 by vfries            #+#    #+#             */
/*   Updated: 2022/12/09 19:20:15 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	slx_bzero(void *ptr, size_t len)
{
	while (len-- > 0)
		*(unsigned char *)ptr++ = (unsigned char)0;
}

int	slx_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
