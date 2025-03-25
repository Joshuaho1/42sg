/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:35:49 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 16:38:27 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	drec(char *str1, int pos, int start, int n)
{
	int	i;

	if (pos == n)
	{
		write(1, str1, n);
		if (str1[0] != '9' - n + 1)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	i = start;
	while (i <= 9)
	{
		str1[pos] = '0' + i;
		drec(str1, pos + 1, i + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	str1[10];

	if ((n <= 0) || (n >= 10))
	{
		return ;
	}
	str1[n] = '\0';
	drec(str1, 0, 0, n);
}

/* #include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_print_combn(atoi(argv[1]));
	}
	return (0);
} */

/* 
ft_print_combn achieves the task recursively. the drec function is called
recusively to build the str1
*/