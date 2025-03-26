/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:59:19 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 23:18:19 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	lastd;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	lastd = nb % 10 + '0';
	write(1, &lastd, 1);
}

/* Recursive function that wirtes any Int type to the terminal.
First section handles the max negative int case because its larger
than a regular int with the negative sign. Next if statement
handles the negative int by writing the negative sign then 
converting to positive. Last part recursively writes the last
digit from back to front.*/