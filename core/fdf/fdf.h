/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:31:49 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 16:20:30 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	height;
}	t_map;

// Debug
void	print_matrix(t_map *map);

// Errors and Free
void	free_map(t_map *map);

// Read Map
t_map	*read_map(char *av);

#endif
