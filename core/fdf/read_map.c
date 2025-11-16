/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:37:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/17 01:26:36 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(char *av)
{
	int		fd;
	t_map	*map;
	char	*data;
	char	**split_d;

	if (!av)
		return ;
	fd = open(map, O_RDONLY);
	data = get_next_line(fd);
	map->height = 1;
	split_d = ft_split(data, ' ');
	map->width = 0;
	while (split_d[map->width] != NULL)
		(map->width)++;
	while (get_next_line(fd) != NULL)
		(map->height)++;
	free_split(split_d);
	close(fd);
	map->matrix = malloc(map->height * sizeof (int *));
	data = get_next_line(fd);
	while (data != NULL)
	{
		
	}
	close(fd);
}
