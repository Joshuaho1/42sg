/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:09:34 by joho              #+#    #+#             */
/*   Updated: 2025/10/03 16:53:01 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_last_node(t_glist *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_buf(t_glist **list, char *buf)
{
	t_glist	*new_node;
	t_glist	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_glist));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buf = buf;
	new_node->next = NULL;
}

int	len_to_newline(t_glist *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			len++;
			if (list->buf[i] == '\n')
				return (len);
			++i;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_glist *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

void	dealloc(t_glist **list, t_glist *clean_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
