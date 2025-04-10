/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:18:00 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 19:13:37 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	length;
	
	if (argc != 2)
	{
		return	(1);
	}
	length = ft_strlen(argv[1]);
	printf("Length: %d\n", length);
	return (0);
}
*/