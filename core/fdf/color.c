/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:13:38 by joho              #+#    #+#             */
/*   Updated: 2025/12/08 23:40:03 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_r(int c)
{
	return ((c >> 16) & 0xFF);
}

static int	get_g(int c)
{
	return ((c >> 8) & 0xFF);
}

static int	get_b(int c)
{
	return (c & 0xFF);
}

static int	interpolate_color(int c1, int c2, double percent)
{
	int	r;
	int	g;
	int	b;

	r = get_r(c1) + (get_r(c2) - get_r(c1)) * percent;
	g = get_g(c1) + (get_g(c2) - get_g(c1)) * percent;
	b = get_b(c1) + (get_b(c2) - get_b(c1)) * percent;
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int z, t_mlx *mlx)
{
	double	percent;
	int		low_color;
	int		high_color;

	low_color = COLOR1;
	high_color = COLOR2;
	if (mlx->z_max - mlx->z_min == 0)
		percent = 0.0;
	else
		percent = (double)(z - mlx->z_min)
			/ (double)(mlx->z_max - mlx->z_min);
	return (interpolate_color(low_color, high_color, percent));
}
