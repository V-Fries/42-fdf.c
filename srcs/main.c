/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/12/07 13:53:36 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "start_fdf.h"
#include "init_fdf.h"
#include "fdf.h"
#include "ft_io.h"

#include "parsing.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc < 2)
		return (ft_putstr("Map is missing\n"), 0);
	init_fdf(&fdf, argv[1]);
	start_fdf(&fdf);
}
