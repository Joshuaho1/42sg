/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:46 by joho              #+#    #+#             */
/*   Updated: 2025/11/22 16:47:24 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (1);
	mlx.map = read_map(av[1]);
	if (!mlx.map)
		return (free_map(mlx.map), 1);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (destroy_free(&mlx), 1);
	mlx.mlx_wind = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, av[1]);
	if (!mlx.mlx_wind)
		return(destroy_free(&mlx), 1);
	mlx = init_mlx(mlx);
	init_image(&mlx);
	render(mlx);
	mlx_key_hook(mlx.mlx_wind, handle_input, &mlx);
	mlx_hook(mlx.mlx_wind, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

// void	print_matrix(t_map *map)
// {
// 	int	y;
// 	int	x;

// 	if (!map || !map.matrix)
// 	{
// 		printf("Map or matrix is NULL\n");
// 		return ;
// 	}

// 	y = 0;
// 	while (y < map.height)
// 	{
// 		x = 0;
// 		while (x < map.width)
// 		{
// 			printf("%d ", map.matrix[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }