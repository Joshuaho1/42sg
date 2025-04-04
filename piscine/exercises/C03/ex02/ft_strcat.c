/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:27:34 by joho              #+#    #+#             */
/*   Updated: 2025/04/01 15:14:23 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen(src) + 1;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{	
		char	*z = malloc(ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1);
		
		strcpy(z, argv[1]);
		ft_strcat(z, argv[2]);
		printf("final: %s\n", z);
		free(z);
	}
	return (0);
}
*/