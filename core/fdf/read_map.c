/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:37:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 16:55:24 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_hw(char *av, t_map *map)
{
	int		fd;
	char	*data;
	char	**split_d;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = get_next_line(fd);
	map->height = 1;
	split_d = ft_split(data, ' ');
	map->width = 0;
	while (split_d[map->width] != NULL)
		(map->width)++;
	free_split(split_d);
	free(data);
	data = get_next_line(fd);
	while (data != NULL)
	{
		(map->height)++;
		free(data);
		data = get_next_line(fd);
	}
	close(fd);
	return ("OK");
}

static void	fill_matrix(char *av, t_map *map)
{
	int		fd;
	int		row;
	int		column;
	char	*data;
	char	**split_d;

	fd = open(av, O_RDONLY);
	data = get_next_line(fd);
	row = 0;
	while (data != NULL)
	{
		split_d = ft_split(data, ' ');
		map->matrix[row] = malloc(map->width * sizeof(int));
		column = 0;
		while (split_d[column] != NULL)
		{
			map->matrix[row][column] = ft_atoi(split_d[column]);
			column++;
		}
		free_split(split_d);
		free(data);
		row++;
		data = get_next_line(fd);
	}
	close(fd);
}

t_map	*read_map(char *av)
{
	t_map	*map;
	char	*status;

	if (!av)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	status = get_hw(av, map);
	if (!status)
		return (NULL);
	map->matrix = malloc(map->height * sizeof(int *));
	fill_matrix(av, map);
	return (map);
}
