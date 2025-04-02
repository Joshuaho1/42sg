/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:14:54 by joho              #+#    #+#             */
/*   Updated: 2025/04/01 16:08:32 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				destle;

	destle = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[destle + i] = src[i];
		i++;
	}
	dest[destle + i] = '\0';
	return (dest);
}
