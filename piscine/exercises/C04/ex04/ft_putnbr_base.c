/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:43:03 by joho              #+#    #+#             */
/*   Updated: 2025/04/02 19:09:35 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		if (base[i] == base[j])
			return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;
	int	based;

	baselen = 0;
	based = valid_base(base);
	if (based)
		return ;
	while (base[baselen] != '\0')
		baselen++;
	if (nbr < 0)
		nbr *= -1;
	

}