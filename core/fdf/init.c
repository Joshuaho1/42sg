/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:16:10 by joho              #+#    #+#             */
/*   Updated: 2025/12/08 22:53:19 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	zoom(int maph, int mapw)
{
	int	w;
	int	span;

	span = maph + mapw;
	if ((WINDOW_WIDTH / span) > ZOOM)
		w = ZOOM;
	else
		w = WINDOW_WIDTH / span;
	return (w);
}

static void	window_size(t_mlx *mlx)
{
	t_point	corners[4];
	int	i;

	mlx->x_min = INT_MAX;
	mlx->x_max = INT_MIN;
	mlx->y_min = INT_MAX;
	mlx->y_max = INT_MIN;
	corners[0] = project(mlx, 0, 0);
	corners[1] = project(mlx, 0, mlx->map->width - 1);
	corners[2] = project(mlx, mlx->map->height - 1, 0);
	corners[3] = project(mlx, mlx->map->height - 1, mlx->map->width - 1);
	i = 0;
	while (i < 4)
	{
		if (corners[i].x < mlx->x_min)
			mlx->x_min = corners[i].x;
		if (corners[i].x > mlx->x_max)
			mlx->x_max = corners[i].x;
		if (corners[i].y < mlx->y_min)
			mlx->y_min = corners[i].y;
		if (corners[i].y > mlx->y_max)
			mlx->y_max = corners[i].y;
		i++;	
	}
}

static void	find_z_minmax(t_mlx *mlx)
{
	int	row;
	int	col;

	mlx->z_min = INT_MAX;
	mlx->z_max = INT_MIN;

	row = 0;
	while (row < mlx->map->height)
	{
		col = 0;
		while (col < mlx->map->width)
		{
			if (mlx->map->matrix[row][col] < mlx->z_min)
				mlx->z_min = mlx->map->matrix[row][col];
			if (mlx->map->matrix[row][col] > mlx->z_max)
				mlx->z_max = mlx->map->matrix[row][col];
			col++;
		}
		row++;
	}
}

void	init_mlx(t_mlx *mlx)
{
	mlx->z_scale = Z_SCALE;
	mlx->zoom = zoom(mlx->map->height, mlx->map->width) * Z_FACTOR;
	mlx->x_offset = 0;
	mlx->y_offset = 0;
	window_size(mlx);
	find_z_minmax(mlx);
	mlx->dyn_width = mlx->x_max - mlx->x_min + 100;
	mlx->dyn_height = mlx->y_max - mlx->y_min + 100;
	mlx->x_offset = mlx->dyn_width / 2 - ((mlx->x_max + mlx->x_min) / 2);
	mlx->y_offset = mlx->dyn_height / 2 - ((mlx->y_max + mlx->y_min) / 2);
}

void	init_image(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->dyn_width, mlx->dyn_height);
	if (!mlx->img_ptr)
		return (destroy_free(mlx));
	mlx->img_pixels_str = mlx_get_data_addr(mlx->img_ptr,
		&(mlx->bpp), &(mlx->line_len), &(mlx->endian));
}
