/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:22:55 by joho              #+#    #+#             */
/*   Updated: 2025/06/10 22:21:07 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = count_digits(n);
	ptr = ft_calloc(digits + 1, sizeof(char));
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		--digits;
		ptr[digits] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
