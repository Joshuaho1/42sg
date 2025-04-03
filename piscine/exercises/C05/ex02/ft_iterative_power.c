/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:56:39 by joho              #+#    #+#             */
/*   Updated: 2025/04/03 19:20:49 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	nbr = nb;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (nb && power == 0)
		return (1);
	while (power > 1)
	{
		nbr *= nb;
		power--;
	}
	return (nbr);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	int	i = ft_iterative_power(atoi(argv[1]), atoi(argv[2]));
	printf("%i\n", i);
}
*/