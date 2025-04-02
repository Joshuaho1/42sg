/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:43:03 by joho              #+#    #+#             */
/*   Updated: 2025/04/03 02:08:29 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_baseintmin(int nbr, char *base, int baselen)
{
	int	lastd;

	write (1, "-", 1);
	ft_putnbr_base(-(nbr / baselen), base);
	lastd = base[-(nbr % baselen)];
	write (1, &lastd, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baselen;
	int		based;
	char	lastd;

	baselen = 0;
	based = valid_base(base);
	if (!based)
		return ;
	while (base[baselen] != '\0')
		baselen++;
	if (nbr == INT_MIN)
	{
		ft_putnbr_baseintmin(nbr, base, baselen);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= baselen)
		ft_putnbr_base((nbr / baselen), base);
	lastd = base[nbr % baselen];
	write(1, &lastd, 1);
}

/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <number> 'base' \n", argv[0]);
		return (1);
	}
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	write(1, "\n", 1);
	return (0);
}
*/