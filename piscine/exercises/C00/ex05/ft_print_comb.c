/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:15:36 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 14:44:36 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write1(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7' || b != '8' || c != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write1(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

/* declare variables as characters because write function works with raw
 bytes. Setting a = '0' assigns it the ASCII value of 48. The while loops
 are conditioned to cap at the maximum value for each digit pos in the comb,
 first pos is 7, second pos is 8, third is 9. Additionally, never let the
 following digits be greater than the previous. Condition for if reached the
 last value*/