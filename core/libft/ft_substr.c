/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:31:06 by joho              #+#    #+#             */
/*   Updated: 2025/06/06 14:52:18 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	cpylen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (NULL);
	cpylen = slen - start;
	if (cpylen > len)
		cpylen = len;
	ptr = malloc(cpylen + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[cpylen] = '\0';
	return (ptr);
}
