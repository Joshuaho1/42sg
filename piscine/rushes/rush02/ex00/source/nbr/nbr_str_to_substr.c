/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_str_to_substr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcheong <lcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:39:22 by marlee            #+#    #+#             */
/*   Updated: 2025/04/06 17:11:53 by lcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*nbr_str_to_substr(char *str, int start, int end)
{
	char	*new_substr;
	int		length;
	int		i;

	i = 0;
	length = end - start + 1;
	new_substr = malloc(length + 1);
	while (i < length)
	{
		new_substr[i] = str[start + i];
		i++;
	}
	new_substr[i] = '\0';
	return (new_substr);
}
