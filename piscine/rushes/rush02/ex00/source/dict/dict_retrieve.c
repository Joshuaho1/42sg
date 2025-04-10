/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_retrieve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:31:16 by lcheong           #+#    #+#             */
/*   Updated: 2025/04/06 19:07:22 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft.h"

char	*dict_retrieve(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(key, dict->keys[i]) == 0)
			return (dict->values[i]);
		i++;
	}
	return (0);
}
