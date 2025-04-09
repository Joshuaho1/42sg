/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:43:51 by joho              #+#    #+#             */
/*   Updated: 2025/04/10 00:01:04 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	valid_base(char *base);
int	base_index(char c, char *base);
int	ft_atoi_base(char *str, char *base);

void	create_str(char *result, int length, char *base, long num)
{
	int		base_len;

	base_len = valid_base(base);
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	result[length] = '\0';
	while (num >= base_len)
	{
		result[--length] = base[num % base_len];
		num /= base_len;
	}
	result[--length] = base[num];
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		length;
	long	num;

	base_len = valid_base(base);
	length = 1;
	num = nbr;
	if (num < 0 && ++length)
		num = -num;
	while (num >= base_len && ++length)
		num /= base_len;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	create_str(result, length, base, nbr);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*result;

	if (!valid_base(base_from) || !valid_base(base_to))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(dec, base_to);
	return (result);
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_convert_base("     ---123", "01234", "01"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", 
	"0123456789abcdef"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "012345"));
	printf("%s\n", ft_convert_base("---7fffffff", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("---+--0001023a", "0123456789", 
	"0123456789"));
	printf("%s\n", ft_convert_base("-0", "0123456789", "abcdef"));
	printf("%s\n", ft_convert_base("   \t\t\t\n05841fff4", 
	"0123456789abcdef", "0123"));
}
*/
