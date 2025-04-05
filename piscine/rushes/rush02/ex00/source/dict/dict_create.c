/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:42:11 by joho              #+#    #+#             */
/*   Updated: 2025/04/05 23:43:54 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"

void	dict_create(t_dict *dict, char *key, char *value)
{
	ft_strcpy(dict->keys[dict->size], key);
	ft_strcpy(dict->values[dict->size], value);
	dict->size += 1;
}
