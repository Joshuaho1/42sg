/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:06:22 by joho              #+#    #+#             */
/*   Updated: 2025/04/05 23:50:54 by joho             ###   ########.fr       */
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
	while (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	ft_strcpy(dest, temp);
	return (i);
}
