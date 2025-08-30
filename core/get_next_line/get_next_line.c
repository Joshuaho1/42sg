/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:09:13 by joho              #+#    #+#             */
/*   Updated: 2025/08/30 23:29:40 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*read_list;
	char			*next_line;

	read_list = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	
	create_list(&read_list, fd);
	
	if (read_list == NULL)
		return (NULL);
	
	next_line = get_line(read_list);

	polish_list(&read_list);
	return (next_line);
}
