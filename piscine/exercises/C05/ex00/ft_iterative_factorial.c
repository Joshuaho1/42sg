/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:26:13 by joho              #+#    #+#             */
/*   Updated: 2025/04/03 17:56:13 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i > 1)
	{
		nb *= i;
		i--;
	}
	return (nb);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	i = ft_iterative_factorial(atoi(argv[1]));
	printf("%i\n", i);
}
*/