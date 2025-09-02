/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:11:39 by joho              #+#    #+#             */
/*   Updated: 2025/09/02 14:06:14 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	ft_count;
	int	std_count;

	/* Compilation Error Tests */
	// ft_printf("%c\n"); // insufficient arguments check
	// printf("%c\n");
	// ft_printf("Hello% World\n"); // no specifier check
	// printf("Hello% World\n");
	// ft_printf("%d\n", 42.42); // mismatched argument data type
	// printf("%d\n", 42.42);
	// ft_printf("ft: %d %d\n\n", INT_MIN - 1, INT_MAX + 1); // int overflow check
	// printf("og: %d %d\n\n", INT_MIN - 1, INT_MAX + 1);
	// ft_printf("%q\n"); // unknown specifier check
	// printf("%q\n\n");
	
	
	/* %c */
	printf("'c' specifier\n");
	ft_count = ft_printf("ft: %c\n", 'A');
	std_count = printf("og: %c\n", 'A');
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);
	ft_printf("ft: %c\n", 65);

	/* %s normal */
	printf("'s' specifier\n");
	ft_count = ft_printf("ft: %s\n", "Josh");
	std_count = printf("og: %s\n", "Josh");
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %s NULL */
	printf("'s' specifier with NULL\n");
	ft_count = ft_printf("ft: %s\n", (char *)NULL);
	std_count = printf("og: %s\n", (char *)NULL);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %p normal */
	printf("'p' specifier\n");
	ft_count = ft_printf("ft: %p\n", (void *)0x1234abcd);
	std_count = printf("og: %p\n", (void *)0x1234abcd);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %p NULL */
	printf("'p' specifier with NULL\n");
	ft_count = ft_printf("ft: %p\n", (void *)NULL);
	std_count = printf("og: %p\n", (void *)NULL);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %p 0 */
	printf("'p' specifier with 0\n");
	ft_count = ft_printf("ft: %p\n", (void *)0);
	std_count = printf("og: %p\n\n", (void *)0);

	/* %d and %i */
	printf("'d' and 'i' specifier\n");
	ft_count = ft_printf("ft: %d %i\n", -42, 42);
	std_count = printf("og: %d %i\n", -42, 42);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %d edge: INT_MIN, INT_MAX */
	printf("'d' specifier INT MIN and MAX\n");
	ft_count = ft_printf("ft: %d %d\n", INT_MIN, INT_MAX);
	std_count = printf("og: %d %d\n\n", INT_MIN, INT_MAX);

	/* %d edge: signed overflow */
	printf("'d' specifier signed overflow\n");
	ft_count = ft_printf("ft: %d\n", 4294967295u + 1);
	std_count = printf("og: %d\n", 4294967295u + 1);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %u edge: UINT_MAX */
	printf("'u' specifier MAX\n");
	ft_count = ft_printf("ft: %u\n", UINT_MAX);
	std_count = printf("og: %u\n", UINT_MAX);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %u edge: unsigned overflow */
	printf("'u' specifier unsigned overflow\n");
	ft_count = ft_printf("ft: %u\n", UINT_MAX + 1);
	std_count = printf("og: %u\n", UINT_MAX + 1);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %x and %X */
	printf("'x' and 'X' specifier\n");
	ft_count = ft_printf("ft: %x %X\n", 48879, 48879);
	std_count = printf("og: %x %X\n", 48879, 48879);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %% */
	printf("percent sign\n");
	ft_printf("%%\n");
	printf("%%\n\n");
	
	/* Mix everything */
	printf("combination specifiers\n");
	ft_count = ft_printf("ft: %c %s %p %d %i %u %x %X\n",
		'Z', "hello", (void *)0x42, INT_MIN, INT_MAX,
		UINT_MAX, 3735928559u, 3735928559u);
	std_count = printf("ft: %c %s %p %d %i %u %x %X\n",
		'Z', "hello", (void *)0x42, INT_MIN, INT_MAX,
		UINT_MAX, 3735928559u, 3735928559u);
	printf("ret ft=%d, og=%d\n", ft_count, std_count);
		
	return (0);
}

