/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:43:51 by joho              #+#    #+#             */
/*   Updated: 2025/04/09 17:26:21 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		length;
	long	num;
	int		i;

	base_len = valid_base(base);
	length = 1;
	num = nbr;
	if (num < 0)
	{
		length++;
		num = -num;
	}
	while (num >= base_len && ++length)
		num /= base_len;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	num = nbr;
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	i = length - 1;
	while (num >= base_len)
	{
		result[i--] = base[num % base_len];
		num /= base_len;
	}
	result[i] = base[num];
	result[length] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*result;

	if (!valid_base(base_from) || !valid_base(base_to))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(dec, base_to);
	return (result);
}
