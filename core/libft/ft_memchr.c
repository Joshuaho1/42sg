/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:55:01 by joho              #+#    #+#             */
/*   Updated: 2025/06/02 15:24:03 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			chr;
	const unsigned char		*ptr;

	i = 0;
	chr = (unsigned char) c;
	ptr = (const unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == chr)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
