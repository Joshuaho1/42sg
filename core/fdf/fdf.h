/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:49 by joho              #+#    #+#             */
/*   Updated: 2025/12/08 23:42:25 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# define _USE_MATH_DEFINES
# include "math.h"
# include <X11/keysym.h>
# include <limits.h>

// Isometric angle is 30 deg in radians
# define ISO_COS 0.866025
# define ISO_SIN 0.5
// ZOOM and Z_FACTOR change the magnification
// Z_SCALE changes scale of the z-axis 
# define ZOOM 20
# define Z_FACTOR 1
# define Z_SCALE 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define COLOR2	0xFFFFFF
# define COLOR1	0x0000FF

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	height;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_wind;
	t_map	*map;
	void	*img_ptr;
	char	*img_pixels_str;
	int		bpp;
	int		endian;
	int		line_len;
	float	zoom;
	float	z_scale;
	int		x_offset;
	int		y_offset;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		z_min;
	int		z_max;
	int		dyn_width;
	int		dyn_height;
}	t_mlx;

// Errors and Free
void	destroy_free(t_mlx *mlx);
void	free_map(t_map *map);

// Read Map, Init
t_map	*read_map(char *av);
void	init_mlx(t_mlx *mlx);
void	init_image(t_mlx *mlx);

// Draw and Render
t_point	*create_point(t_map *map, int row, int col);
void	my_pixel_put(t_mlx *mlx, int x, int y, int color);
void	isometric(t_point *p);
t_point	project(t_mlx *mlx, int row, int col);
void	draw_line(t_mlx *mlx, t_point a, t_point b);
void	render(t_mlx *mlx);

// Hooks
int		handle_input(int keysym, t_mlx *mlx);
int		close_window(t_mlx *mlx);

// Color
int		get_color(int z, t_mlx *mlx);

#endif
