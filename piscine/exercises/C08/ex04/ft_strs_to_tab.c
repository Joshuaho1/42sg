/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:30:33 by joho              #+#    #+#             */
/*   Updated: 2025/04/10 13:03:07 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	i = 0;
	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int i;
	t_stock_str *arr;

	arr = ft_strs_to_tab(argc - 1, argv + 1);
	if (!arr)
		return (1);
	i = 0;
	while (arr[i].str != NULL)
	{
		printf("size: %d\n", arr[i].size);
		printf("str: %s\n", arr[i].str);
		printf("copy: %s\n", arr[i].copy);
		i++;
	}
	return (0);
}
*/
