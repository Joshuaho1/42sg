/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcheong <lcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:10:59 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 17:56:55 by lcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "nbr.h"
#include <stdlib.h>

t_nbr_buffer	*new_nbr_buffer(void)
{
	t_nbr_buffer	*buffer;

	buffer = malloc(sizeof(t_nbr_buffer));
	buffer->words = malloc(sizeof(char *));
	buffer->words[0] = 0;
	buffer->size = 0;
	return (buffer);
}

void	print_nbr_buffer(t_nbr_buffer *buffer)
{
	int	i;

	i = 0;
	while (i < buffer->size)
	{
		ft_putstr(buffer->words[i]);
		if (i < buffer->size - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	add_nbr_buffer(t_nbr_buffer *buffer, char *word)
{
	char	**words;
	int		i;

	words = malloc(sizeof(char *) * (buffer->size + 1));
	i = 0;
	while (i < buffer->size)
	{
		words[i] = buffer->words[i];
		i++;
	}
	words[i] = word;
	free(buffer->words);
	buffer->words = words;
	buffer->size += 1;
}

void	destory_nbr_buffer(t_nbr_buffer *buffer)
{
	int	i;

	i = 0;
	while (i < buffer->size)
	{
		free(buffer->words[i]);
		i++;
	}
	free(buffer);
}
