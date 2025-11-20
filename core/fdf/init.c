/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:16:10 by joho              #+#    #+#             */
/*   Updated: 2025/11/20 21:46:38 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_mlx	init_mlx(char *filename)
// {
// 	t_mlx	mlx;
	
// 	mlx.map = read_map(filename);
// 	if (!mlx.map)
// 		return (destroy_free(mlx), 1);
// 	mlx.mlx_ptr = mlx_init();
// 	if (!mlx.mlx_ptr)
// 		return (1);
// 	mlx.mlx_wind = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH,
// 		WINDOW_HEIGHT, filename);
// 	if (!mlx.mlx_wind)
// 		return(destroy_free(mlx), 1);
// 	return (mlx);
// }

void	init_image(t_mlx mlx)
{
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.img.img_pixels_ptr = mlx_get_data_addr(mlx.img.img_ptr,
		&(mlx.img.bits_per_pixel), &(mlx.img.line_len), &(mlx.img.endian));
}
