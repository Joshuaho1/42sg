#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

int	putchar(int n)
{
	return write(1, &n, 1);
}

int	printstr(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		putchar((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	printnum(long long n, int base, int uppercase, int sign)
{
	char			*digits;
	char			buf[65];
	unsigned long	num;
	int				i;
	int				len;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = 0;
	if (sign && n < 0)
	{
		len += putchar('-');
		num = (unsigned long)(-n);
	}
	else
		num = (unsigned long)n;
	i = 0;
	if (num == 0)
		buf[i++] = '0';
	while (num > 0)
	{
		buf[i++] = digits[num % base];
		num /= base;
	}
	while (--i >= 0)
		len += putchar(buf[i]);
	return (len);
}
