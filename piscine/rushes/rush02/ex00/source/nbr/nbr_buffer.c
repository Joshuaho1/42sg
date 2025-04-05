/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:10:59 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 00:14:15 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "nbr.h"
#include "ft.h"

t_nbr_buffer	*new_nbr_buffer(void)
{
	t_nbr_buffer	*buffer;

	buffer = malloc(sizeof(t_nbr_buffer));
	buffer->words = malloc(sizeof(char *));
	buffer->words[0] = 0;
	buffer->size = 0;
	return (buffer);
}
