/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:55:50 by joho              #+#    #+#             */
/*   Updated: 2025/03/24 19:44:56 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	bspace(int r, int c, int x, int y)
{
	if (((r == 1) || (r == y)) && ((c != 1) && (c != (x))))
	{
		ft_putchar('B');
	}
	if ((r != 1) && (r != (y)))
	{
		if ((c == 1) || (c == (x)))
		{
			ft_putchar('B');
		}
	}
	if ((r != 1) && (r != (y)) && ((c != 1) && (r != (x))))
	{
		ft_putchar(' ');
	}
}

void	errorhandle(int x, int y)
{
	if ((x <= 0) || (y <= 0))
	{
		break ;
	}
}

void	rush(int x, int y)
{
	int	c;
	int	r;

	errorhandle(x, y);
	r = 1;
	while (r <= y)
	{
		c = 1;
		while (c <= x)
		{
			if (((r == 1) && (c == 1)) || ((r == y) && (c == x)))
			{
				ft_putchar('A');
			}
			if (((r == 1) && (c == x)) || ((r == y) && (c == 1)))
			{
				ft_putchar('C');
			}
			bspace(r, c, x, y);
			c++;
		}
		r++;
		ft_putchar('\n');
	}
}
