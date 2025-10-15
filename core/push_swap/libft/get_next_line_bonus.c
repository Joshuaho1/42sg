/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:09:13 by joho              #+#    #+#             */
/*   Updated: 2025/10/03 16:52:38 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_newline(t_glist *list)
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

void	make_list(t_glist **list, int fd)
{
	int		chars_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = '\0';
		add_buf(list, buf);
	}
}

char	*get_line(t_glist *list)
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

void	prep_next(t_glist **list)
{
	t_glist	*last_node;
	t_glist	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_glist));
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
	static t_glist	*read_list[FD_MAX];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	make_list(&read_list[fd], fd);
	if (read_list[fd] == NULL)
		return (NULL);
	next_line = get_line(read_list[fd]);
	prep_next(&read_list[fd]);
	return (next_line);
}
