/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:18:41 by joho              #+#    #+#             */
/*   Updated: 2025/10/03 16:27:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_specifier(char spec, va_list ap)
{
	int	bytecount;

	bytecount = 0;
	if (spec == 'c')
		bytecount += printchar(va_arg(ap, int));
	else if (spec == 's')
		bytecount += printstr(va_arg(ap, char *));
	else if (spec == 'p')
		bytecount += printp(va_arg(ap, void *));
	else if (spec == 'd')
		bytecount += printnum(va_arg(ap, int), 10, 0, 1);
	else if (spec == 'i')
		bytecount += printnum(va_arg(ap, int), 10, 0, 1);
	else if (spec == 'u')
		bytecount += printnum(va_arg(ap, unsigned int), 10, 0, 0);
	else if (spec == 'x')
		bytecount += printnum(va_arg(ap, unsigned int), 16, 0, 0);
	else if (spec == 'X')
		bytecount += printnum(va_arg(ap, unsigned int), 16, 1, 0);
	else
		bytecount += write(1, &spec, 1);
	return (bytecount);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytecount;

	bytecount = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			bytecount += check_specifier(*++format, ap);
		else
			bytecount += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (bytecount);
}
