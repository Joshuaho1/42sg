/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:15:01 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 19:23:11 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"

int	dict_parse(t_dict *dict, char *str)
{
	int		i;
	int		check;
	char	*nbr;
	char	*wrd;

	i = 0;
	check = 0;
	while (str[i])
	{
		nbr = malloc(sizeof(char) * 64);
		wrd = malloc(sizeof(char) * 64);
		check = copy_nbr(nbr, str + i);
		if (!nbr || !wrd || check == -1)
			return (-1);
		i += check;
		i += skip_to_word(str + i);
		i += copy_word(wrd, str + i);
		i += skip_to_num(str + i);
		dict_create(dict, nbr, wrd);
		free(nbr);
		free(wrd);
	}
	return (0);
}
