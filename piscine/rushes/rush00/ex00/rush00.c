/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:55:50 by joho              #+#    #+#             */
/*   Updated: 2025/03/24 19:44:23 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	dashspace(int r, int c, int x, int y)
{
	if ((r != 1) && (r != (y)))
	{
		if ((c == 1) || (c == (x)))
		{
			ft_putchar('|');
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
			if (((r == 1) || (r == (y))) && ((c == 1) || (c == x)))
			{
				ft_putchar('o');
			}
			if (((r == 1) || (r == y)) && ((c != 1) && (c != (x))))
			{
				ft_putchar('-');
			}
			dashspace(r, c, x, y);
			c++;
		}
		r++;
		ft_putchar('\n');
	}
}
