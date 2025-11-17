/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:38:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 17:59:17 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_point(t_map *map, int row, int col)
{
	t_point	*p;

	p->x = col;
	p->y = row;
	p->z = map->matrix[row][col];
	return (p);
}

void	isometric(t_point *p)
{
	float	prev_x;
	float	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(ISO_ANGLE);
	p->y = (prev_x + prev_y) * sin(ISO_ANGLE) - p->z;
}

t_point	*project(t_fdf *fdf, int row, int col)
{
	t_point	*p;

	p->x = col;
	p->y = row;
	p->z = fdf->map->matrix[row][col];
	p->x *= fdf->zoom;
	p->y *= fdf->zoom;
	p->z *= fdf->z_scale;
	isometric(p);
	p->x += fdf->x_offset;
	p->y += fdf->y_offset;
	return (p);
}

// Brensenham's algorithm
void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	float	x_step;
	float	y_step;
	int		max_step;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max_step = max(abs(x_step), abs(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while (max_step--)
	{
		mlx_pixel_put(fdf, (int)a.x, (int)a.y);
		a.x += x_step;
		a.y += y_step;
	}
}

void	render(t_fdf *fdf)
{
	int	row;
	int	col;

	while (row < fdf->map->height)
	{
		while (col < fdf->map->width)
		{
			if (col )
		}
	}
}