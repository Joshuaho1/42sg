/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:52:55 by joho              #+#    #+#             */
/*   Updated: 2025/04/05 23:53:47 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

ssize_t	file_size(char *file)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	int		file_open;

	file_open = open(file, 00);
	bytes_read = read(file_open, buffer, BUFFER_SIZE);
	close(file_open);
	return (bytes_read);
}

char	*read_file(char *file)
{
	int		file_open;
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = file_size(file);
	if (bytes_read == -1)
	{
		ft_error("Error\n");
		return (NULL);
	}
	file_open = open(file, 00);
	buffer = (char *)malloc(bytes_read);
	bytes_read = read(file_open, buffer, bytes_read);
	if (bytes_read == -1)
	{
		ft_error("Error\n");
		close(file_open);
		return (NULL);
	}
	close(file_open);
	return (buffer);
}
