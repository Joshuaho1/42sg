/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:21:24 by joho              #+#    #+#             */
/*   Updated: 2025/04/02 18:41:44 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

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
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int result = 0;
	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return (1);
	}
	result = ft_atoi(argv[1]);
	printf("%i\n", result);
	return (0);
}
*/