/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:39:39 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 19:24:58 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

static char	**str_array_new(void)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(char *) * 128);
	while (i < 128)
	{
		array[i] = malloc(sizeof(char) * 128);
		i++;
	}
	return (array);
}

t_dict	new_dict(void)
{
	t_dict	dict;

	dict.keys = str_array_new();
	dict.values = str_array_new();
	dict.size = 0;
	return (dict);
}
