/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:20:02 by vfries            #+#    #+#             */
/*   Updated: 2022/12/06 01:19:02 by vfries           ###   ########lyon.fr   */
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
	// (void)argc;
	// (void)argv;
	// t_fdf	fdf;

	// parse_map(&fdf.map, "maps/42.fdf");
	// for (int y = 0; y < fdf.map.y_size; y++)
	// {
	// 	for (int x = 0; x < fdf.map.x_size; x++)
	// 	{
	// 		printf("(%.0f, %.0f, %.0f, %.0f), ", fdf.map.o[y][x].x, fdf.map.o[y][x].y, fdf.map.o[y][x].z, fdf.map.o[y][x].w);
	// 	}
	// 	ft_putstr("\n");
	// }
}
