/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:16:10 by joho              #+#    #+#             */
/*   Updated: 2025/11/21 16:24:53 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	init_mlx(t_mlx mlx)
{
	mlx.x_offset = WINDOW_WIDTH / 2;
	mlx.y_offset = WINDOW_HEIGHT / 2;
	mlx.z_scale = Z_SCALE;
	mlx.zoom = ZOOM;
	return (mlx);
}

void	init_image(t_mlx mlx)
{
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx.img.img_ptr)
		return (destroy_free(mlx));
	mlx.img.img_pixels_ptr = mlx_get_data_addr(mlx.img.img_ptr,
		&(mlx.img.bits_per_pixel), &(mlx.img.line_len), &(mlx.img.endian));
}
