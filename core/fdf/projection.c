/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:38:29 by joho              #+#    #+#             */
/*   Updated: 2025/12/08 22:43:46 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_point(t_map *map, int row, int col)
{
	t_point	*p;

	p = malloc(sizeof (t_point));
	if (!p)
		return (NULL);
	p->x = col;
	p->y = row;
	p->z = map->matrix[row][col];
	return (p);
}

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pix;

	if (x < 0 || x >= mlx->dyn_width || y < 0 || y >= mlx->dyn_height)
		return ;
	pix = mlx->img_pixels_str + (y * mlx->line_len + x * (mlx->bpp / 8));
	*((unsigned int *)pix) = color;
}

void	isometric(t_point *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * ISO_COS;
	p->y = (prev_x + prev_y) * ISO_SIN - p->z;
}

t_point	project(t_mlx *mlx, int row, int col)
{
	t_point	p;

	p.x = col;
	p.y = row;
	p.z = mlx->map->matrix[row][col];
	p.x *= mlx->zoom;
	p.y *= mlx->zoom;
	p.z *= mlx->z_scale;
	isometric(&p);
	p.x += mlx->x_offset;
	p.y += mlx->y_offset;
	return (p);
}

void	bresenham(t_mlx *mlx, t_point a, t_point b)
{
	int		error[2];
	t_point	base;

	base.x = a.x;
	base.y = a.y;
	error[0] = abs(b.x - a.x) - abs(b.y - a.y);
	while (base.x != b.x || base.y != b.y)
	{
		my_pixel_put(mlx, base.x, base.y, get_color(a.z, mlx));
		error[1] = 2 * error[0];
		if (error[1] > -abs(b.y -a.y))
		{
			error[0] -= abs(b.y - a.y);
			base.x += (a.x < b.x);
			base.x -= (b.x < a.x);
		}
		if (error[1] < abs(b.x - a.x))
		{
			error[0] += abs(b.x - a.x);
			base.y += (a.y < b.y);
			base.y -= (b.y < a.y);
		}
	}
}

// DDA algorithm
void	draw_line(t_mlx *mlx, t_point a, t_point b)
{
	float	x_step;
	float	y_step;
	float	max_step;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max_step = fmax(fabs(x_step), fabs(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while (max_step--) // float in while loop ?
	{
		my_pixel_put(mlx, (int)a.x, (int)a.y, get_color(a.z, mlx));
		a.x += x_step;
		a.y += y_step;
	}
}

void	render(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < mlx->map->height)
	{
		col = 0;
		while (col < mlx->map->width)
		{
			if (col < mlx->map->width - 1)
				bresenham(mlx, project(mlx, row, col),
				project(mlx, row, col + 1));
			if (row < mlx->map->height - 1)
				bresenham(mlx, project(mlx, row, col),
				project(mlx, row + 1, col));
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_wind,
		mlx->img_ptr, 0, 0);
}
