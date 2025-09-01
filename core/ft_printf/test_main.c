/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:11:39 by joho              #+#    #+#             */
/*   Updated: 2025/09/01 23:49:51 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	ft_count;
	int	std_count;

	/* %c */
	//ft_printf("%c");
	ft_count = ft_printf("ft: %c\n", 'A');
	std_count = printf("og: %c\n", 'A');
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %s normal */
	ft_count = ft_printf("ft: %s\n", "Josh");
	std_count = printf("og: %s\n", "Josh");
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %s NULL */
	ft_count = ft_printf("ft: %s\n", (char *)NULL);
	std_count = printf("og: %s\n", (char *)NULL);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %p normal */
	ft_count = ft_printf("ft: %p\n", (void *)0x1234abcd);
	std_count = printf("og: %p\n", (void *)0x1234abcd);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %p NULL */
	ft_count = ft_printf("ft: %p\n", (void *)NULL);
	std_count = printf("og: %p\n", (void *)NULL);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %d and %i */
	ft_count = ft_printf("ft: %d %i\n", -42, 42);
	std_count = printf("og: %d %i\n", -42, 42);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %d edge: INT_MIN, INT_MAX */
	ft_count = ft_printf("ft: %d %d\n", INT_MIN, INT_MAX);

	/* %u edge: UINT_MAX */
	ft_count = ft_printf("ft: %u\n", UINT_MAX);
	std_count = printf("og: %u\n", UINT_MAX);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* %x and %X */
	ft_count = ft_printf("ft: %x %X\n", 48879, 48879);
	std_count = printf("og: %x %X\n", 48879, 48879);
	printf("ret ft=%d, og=%d\n\n", ft_count, std_count);

	/* Unknown specifier */
	//ft_count = ft_printf("ft: %q\n");

	/* Mix everything */
	ft_count = ft_printf("ft: %c %s %p %d %i %u %x %X\n",
		'Z', "hello", (void *)0x42, INT_MIN, INT_MAX,
		UINT_MAX, 3735928559u, 3735928559u);
		
	return (0);
}

