/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:21:31 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 22:10:20 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include "nbr.h"

static int	nbr_store(t_nbr_buffer *nbrbuf, t_dict *dict, char *str)
{
	char	*word;

	word = dict_retrieve(dict, str);
	if (!word)
		return (-1);
	add_nbr_buffer(nbrbuf, word);
	return (0);
}

static int	nbr_tens(t_nbr_buffer *nbrbuf, t_dict *dict, char *str)
{
	int	len;

	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_store(nbrbuf, dict, nbr_str_to_substr(str, 0, 0)));
	if (str[0] == '1')
		return (nbr_store(nbrbuf, dict, str));
	if (nbr_store(nbrbuf, dict, nbr_zeropadding(str[0], 1)) == -1)
		return (-1);
	if (str[1] != '0')
		return (nbr_store(nbrbuf, dict, nbr_str_to_substr(str, 1, 1)));
	return (0);
}

static int	nbr_hundreds(t_nbr_buffer *nbrbuf, t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		return (nbr_store(nbrbuf, dict, "0"));
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_store(nbrbuf, dict, str));
	if (len == 2)
		return (nbr_tens(nbrbuf, dict, nbr_str_to_substr(str, 0, 1)));
	if (nbr_store(nbrbuf, dict, nbr_str_to_substr(str, 0, 0)) == -1)
		return (-1);
	if (nbr_store(nbrbuf, dict, "100") == -1)
		return (-1);
	if (nbr_tens(nbrbuf, dict, nbr_str_to_substr(str, 1, 2)) == -1)
		return (-1);
	return (0);
}

int	nbr_chunk(t_nbr_buffer *nbrbuf, t_dict *dict, char *str)
{
	int		i;
	int		chunk;
	int		remain;
	char	*digits;

	i = 0;
	remain = ft_strlen(str);
	while (i < ft_strlen(str))
	{
		chunk = remain % 3;
		if (chunk == 0)
			chunk = 3;
		digits = nbr_str_to_substr(str, i, i + chunk - 1);
		if (nbr_hundreds(nbrbuf, dict, digits) == -1)
			return (-1);
		if (remain - chunk >= 3
			&& !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
			if (nbr_store(nbrbuf, dict,
					nbr_zeropadding('1', remain - chunk)) == -1)
				return (-1);
		i += chunk;
		remain -= chunk;
	}
	return (0);
}
