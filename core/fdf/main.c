/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:46 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 16:20:51 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map *map;

	if (ac != 2)
		return (1);
	map = read_map(av[1]);
	printf("Map loaded: %dx%d\n", map->width, map->height);
	print_matrix(map);
	free_map(map);
	return (0);
}

void	print_matrix(t_map *map)
{
	int	y;
	int	x;

	if (!map || !map->matrix)
	{
		printf("Map or matrix is NULL\n");
		return ;
	}

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("%d ", map->matrix[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}