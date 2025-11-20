/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:38:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/21 00:20:49 by joho             ###   ########.fr       */
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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pix;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pix = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

void	isometric(t_point p)
{
	float	prev_x;
	float	prev_y;

	prev_x = p.x;
	prev_y = p.y;
	p.x = (prev_x - prev_y) * cos(ISO_ANGLE);
	p.y = (prev_x + prev_y) * sin(ISO_ANGLE) - p.z;
}

t_point	project(t_mlx mlx, int row, int col)
{
	t_point	p;

	p.x = col;
	p.y = row;
	p.z = mlx.map->matrix[row][col];
	p.x *= mlx.zoom;
	p.y *= mlx.zoom;
	p.z *= mlx.z_scale;
	isometric(p);
	p.x += mlx.x_offset;
	p.y += mlx.y_offset;
	return (p);
}

// DDA algorithm
void	draw_line(t_mlx mlx, t_point a, t_point b)
{
	float	x_step;
	float	y_step;
	float	max_step;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max_step = fmax(fabs(x_step), fabs(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while (max_step--)
	{
		my_pixel_put(mlx.img.img_ptr, (int)a.x, (int)a.y, COLOR);
		a.x += x_step;
		a.y += y_step;
	}
}

void	render(t_mlx mlx)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < mlx.map->height)
	{
		col = 0;
		while (col < mlx.map->width)
		{
			if (col < mlx.map->width - 1)
				draw_line(mlx, project(mlx, row, col),
				project(mlx, row, col + 1));
			if (row < mlx.map->height - 1)
				draw_line(mlx, project(mlx, row, col),
				project(mlx, row + 1, col));
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_wind,
		mlx.img.img_ptr, 0, 0);
}
