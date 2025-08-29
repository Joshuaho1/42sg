/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:20:48 by joho              #+#    #+#             */
/*   Updated: 2025/08/27 16:58:30 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int n)
{
	return (write(1, &n, 1));
}

int	printstr(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str != '\0')
	{
		printchar((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	printp(void *ptr)
{
	unsigned long	addr;
	char			buf[17];
	char			*digits;
	int				i;
	int				len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	digits = "0123456789abcdef";
	i = 0;
	while (addr > 0)
	{
		buf[i++] = digits[addr % 16];
		addr /= 16;
	}
	len = write(1, "0x", 2);
	if (i == 0)
		buf[i++] = '0';
	while (--i >= 0)
		len += printchar(buf[i]);
	return (len);
}

char	*check_upper(int uppercase)
{
	char	*digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	return (digits);
}

int	printnum(long long n, int base, int uppercase, int sign)
{
	char			*digits;
	char			buf[65];
	unsigned long	num;
	int				len;
	int				i;

	digits = check_upper(uppercase);
	len = 0;
	i = 0;
	num = (unsigned long)n;
	if (sign && n < 0)
	{
		len += printchar('-');
		num *= -1;
	}
	if (num == 0)
		buf[i++] = '0';
	while (num > 0)
	{
		buf[i++] = digits[num % base];
		num /= base;
	}
	while (--i >= 0)
		len += printchar(buf[i]);
	return (len);
}
