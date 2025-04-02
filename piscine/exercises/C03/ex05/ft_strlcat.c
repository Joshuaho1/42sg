/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:25 by joho              #+#    #+#             */
/*   Updated: 2025/04/01 17:47:11 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	fsize;
	unsigned int	srclen;
	unsigned int	destlen;

	if (!dest || !src)
		return (0);
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	fsize = size - destlen -1;
	if (size <= destlen)
		return (size + srclen);
	i = 0;
	while (src[i] != '\0' && i < fsize)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen + destlen);
}
