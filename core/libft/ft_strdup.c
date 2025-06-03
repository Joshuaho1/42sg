/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:54 by joho              #+#    #+#             */
/*   Updated: 2025/06/03 17:01:11 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		strsize;

	strsize = (ft_strlen((char *) s) + 1);
	ptr = malloc(strsize);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, strsize);
	return (ptr);
}
