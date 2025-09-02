/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:09:13 by joho              #+#    #+#             */
/*   Updated: 2025/09/02 16:01:01 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->buf[i] != '\0' && last_node->buf[i] != '\n')
		++i;
	while (last_node->buf[i] != '\0' && last_node->buf[++i])
		buf[k++] = last_node->buf[i];
	buf[k] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

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
