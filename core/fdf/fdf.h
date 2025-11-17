/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:49 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 17:39:33 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
#define _USE_MATH_DEFINES
# include "math.h"

// Isometric angle is 30 deg in radians
#define ISO_ANGLE 0.523599
#define ZOOM 20;
#define Z_SCALE 1;
#ifndef d2r
# define d2r(x) ((x) * (M_PI)/180)
#endif

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	height;
}	t_map;
typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	float	zoom;
	float	z_scale;
	int		x_offset;
	int		y_offset;
}	t_fdf;



// Debug
void	print_matrix(t_map *map);

// Errors and Free
void	free_map(t_map *map);

// Read Map
t_map	*read_map(char *av);

#endif
