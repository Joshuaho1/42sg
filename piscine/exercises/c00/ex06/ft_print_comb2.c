/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:52:38 by joho              #+#    #+#             */
/*   Updated: 2025/03/24 14:57:11 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_str(int num, char *str)
{
	if (num < 10)
	{
		str[0] = '0';
		str[1] = num + '0';
	}
	else
	{
		str[0] = (num / 10) + '0';
		str[1] = (num % 10) + '0';
	}
}

void	ft_print_comb2(void)
{
	int		p1;
	int		p2;
	char	str1[2];
	char	str2[2];

	p1 = 00;
	p2 = 00;
	while (p1 <= 98)
	{
		p2 = p1 + 1;
		while (p2 <= 99)
		{
			int_to_str(p1, str1);
			int_to_str(p2, str2);
			write(1, str1, 2);
			write(1, " ", 1);
			write(1, str2, 2);
			if ((p1 != 98) && (p1 != 99))
			{
				write(1, ", ", 2);
			}
			p2++;
		}
		p1++;
	}
}
