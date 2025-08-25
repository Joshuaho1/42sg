#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <libft.h>

int	check_specifier(char spec, va_list ap)
{
	int	bytecount;

	bytecount = 0;
	if (spec == 'c')
		bytecount += printchar(va_arg(ap, int));
	else if (spec == 's')
		bytecount += printstr(va_arg(ap, char *));
	else if (spec == 'p')
		bytecount += printptr(va_arg(ap, char *)); // hexadecimal void pointer
	else if (spec == 'd')
		bytecount += printd(va_arg(ap, float)); // decimal base 10
	else if (spec == 'i')
		bytecount += printi(va_arg(ap, int)); // integer base 10
	else if (spec == 'u')
		bytecount += printu(va_arg(ap, unsigned float)); // unsigned decimal base 10
	else if (spec == 'x')
		bytecount += printxl(va_arg(ap, unsigned int), 16); // hexadecimal base 16 lowercase
	else if (spec == 'X')
		bytecount += printxu(va_arg(ap, int), 16); // hexadecimal base 16 uppercase
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
	}
	va_end(ap);
	return (bytecount);
}
