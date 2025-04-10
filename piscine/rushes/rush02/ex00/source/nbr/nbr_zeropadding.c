/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_add_0s_behind_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcheong <lcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:56:58 by marlee            #+#    #+#             */
/*   Updated: 2025/04/06 17:20:27 by lcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*nbr_zeropadding(char c, int nbr_of_zeros)
{
	char	*pad;
	int		i;
	int		length;

	length = 1 + nbr_of_zeros;
	pad = malloc(length + 1);
	pad[0] = c;
	i = 1;
	while (i < length)
	{
		pad[i] = '0';
		i++;
	}
	pad[i] = '\0';
	return (pad);
}
