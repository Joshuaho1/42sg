/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:37:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/16 19:21:01 by joho             ###   ########.fr       */
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
	map->height = 0;
	data = get_next_line(fd);
	split_d = ft_split(data, ' ');
	map->width = 0;
	while (split_d[map->width] != NULL)
		(map->width)++;
	while (data = get_next_line(fd) != NULL)
		(map->height)++;
	map->matrix = malloc(map->height * sizeof (int *));
	
	close(fd);
}
