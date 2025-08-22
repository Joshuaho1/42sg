#include <stdlib.h>
#include <stdarg.h>
#include <libft.h>

int	check_specifier(char c, *type)
{

}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);`
	while (*format != '\0')
	{
		if (*++format == '%')
			count += check_specifier(*++format, va_arg(ap, *type));
		else
			count += write(1, format, 1);
	}
	va_end(ap);
	return (count);
}
