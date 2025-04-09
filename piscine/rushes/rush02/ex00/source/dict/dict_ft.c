/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:06:22 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 22:57:23 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	skip_to_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ':' && str[i] != '\n')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	skip_to_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	copy_nbr(char *dest, char *str)
{
	int		i;
	char	temp[64];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	ft_strcpy(dest, temp);
	return (i);
}

int	copy_word(char *dest, char *str)
{
	int		i;
	char	temp[64];

	i = 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	ft_strcpy(dest, temp);
	return (i);
}
