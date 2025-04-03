/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:37:57 by joho              #+#    #+#             */
/*   Updated: 2025/04/03 12:26:33 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	valid_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	baselen;
	int	sign;
	int	result;

	baselen = valid_base(base);
	if (!baselen)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (base_index(str[i], base) < baselen))
	{
		result = (result * baselen) + base_index(str[i], base);
		i++;
	}
	return (result * sign);
}
