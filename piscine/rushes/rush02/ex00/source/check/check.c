/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:21:09 by joho              #+#    #+#             */
/*   Updated: 2025/04/05 20:47:13 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dict_file(char *dict)
{
	int		fileopen;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fileopen = open(dict, 00);
	if (fileopen == -1)
		return (0);
	bytes_read = read(fileopen, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		close(fileopen);
		return (0);
	}
	close(fileopen);
	return (1);
}

int	check_args(int argc, char **argv, char *default_dict)
{
	if (argc == 2)
	{
		if (!check_digits(argv[1]))
			return (0);
		if (!check_dict_file(default_dict))
			return (-1);
	}
	else if (argc == 3)
	{
		if (!check_dict_file(argv[1]))
			return (-1);
		if (!check_digits(argv[2]))
			return (0);
	}
	else
		return (0);
	return (1);
}
