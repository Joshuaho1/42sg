/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:46 by joho              #+#    #+#             */
/*   Updated: 2025/12/09 17:14:33 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_live(t_mlx	*mlx);

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1);
	close(fd);
	mlx.map = read_map(av[1]);
	if (!mlx.map)
		return (free_map(mlx.map), 1);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (destroy_free(&mlx), 1);
	init_mlx(&mlx);
	mlx.mlx_wind = mlx_new_window(mlx.mlx_ptr, mlx.dyn_width,
			mlx.dyn_height, av[1]);
	if (!mlx.mlx_wind)
		return (destroy_free(&mlx), 1);
	init_image(&mlx);
	render(&mlx);
	mlx_live(&mlx);
	return (0);
}

static void	mlx_live(t_mlx	*mlx)
{
	mlx_key_hook(mlx->mlx_wind, handle_input, mlx);
	mlx_hook(mlx->mlx_wind, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx_ptr);
}
