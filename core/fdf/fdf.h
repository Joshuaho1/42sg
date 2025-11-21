/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:49 by joho              #+#    #+#             */
/*   Updated: 2025/11/21 16:22:49 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
#define _USE_MATH_DEFINES
# include "math.h"
# include <X11/keysym.h>

// Isometric angle is 30 deg in radians
#define ISO_ANGLE 0.523599
#define ZOOM 20
#define Z_SCALE 1
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define COLOR	0xFFFFFF

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	height;
}	t_map;
typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_wind;
	t_map	*map;
	t_img	img;
	float	zoom;
	float	z_scale;
	int		x_offset;
	int		y_offset;
}	t_mlx;

// Debug
void	print_matrix(t_map *map);

// Errors and Free
void	destroy_free(t_mlx mlx);
void	free_map(t_map *map);

// Read Map, Init
t_map	*read_map(char *av);
t_mlx	init_mlx(t_mlx mlx);
void	init_image(t_mlx mlx);

// Draw and Render
t_point	*create_point(t_map *map, int row, int col);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	isometric(t_point p);
t_point	project(t_mlx mlx, int row, int col);
void	draw_line(t_mlx mlx, t_point a, t_point b);
void	render(t_mlx mlx);

// Hooks
int		handle_input(int keysym, t_mlx mlx);
int		close_window(t_mlx mlx);

#endif
