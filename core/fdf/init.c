/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:16:10 by joho              #+#    #+#             */
/*   Updated: 2025/11/25 01:54:07 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->x_offset = WINDOW_WIDTH / 2;
	mlx->y_offset = WINDOW_HEIGHT / 2;
	mlx->z_scale = Z_SCALE;
	mlx->zoom = ZOOM;
}

void	init_image(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img_ptr)
		return (destroy_free(mlx));
	mlx->img_pixels_str = mlx_get_data_addr(mlx->img_ptr,
		&(mlx->bpp), &(mlx->line_len), &(mlx->endian));
}
