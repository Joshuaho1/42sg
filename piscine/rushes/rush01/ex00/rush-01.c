/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:28:34 by joho              #+#    #+#             */
/*   Updated: 2025/03/29 19:45:59 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	numcheck(char *str, int *colups, int *coldowns, int *rowlefts, int *rowrights, int limit)
{
	int	i;
	int	l;

	i = 0;
	l = limit;
	int j = 0;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= (l + '0'))
		{
			if (j/4 < 1)
				colups[j%4] = str[i] - '0';
			else if (j/4 < 2)
				coldowns[j%4] = str[i] - '0';
			else if (j/4 < 3)
				rowlefts[j%4] = str[i] - '0';
			else if (j/4 < 4)
				rowrights[j%4] = str[i] - '0';
			else
				return (0);
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/*int	makegrid(char *str, int gridsz)
{
	char grid[gridsz][gridsz];
	int	row;
	int	col;
	int	i;
	int	div;
	int	mod;

	i = 0;
	while (str[i])
	{
		if (str[i] == 1 || str[i] == gridsz)
			{
				div = i / gridsz;
				mod = i % gridsz;
				if (i >= 0 && <= )
			}
	}



}*/

void print_array(int *array)
{
	int i = 0;
	while (array[i])
	{
		printf("%d", array[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*vstr;
	int		i;
	int		limit;
	int		*colups = (int *) malloc(sizeof(int) * 4);
	int		*coldowns = (int *) malloc(sizeof(int) * 4);
	int		*rowlefts = (int *) malloc(sizeof(int) * 4);
	int		*rowrights = (int *)malloc(sizeof(int) * 4);

	limit = 4;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	vstr = argv[1];
	if(numcheck(vstr, colups, coldowns, rowlefts, rowrights, limit) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	printf("colups: ");
	print_array(colups);
	printf("\ncoldowns: ");
	print_array(coldowns);
	printf("\nrowlefts: ");
	print_array(rowlefts);
	printf("\nrowrights: ");
	print_array(rowrights);
	printf("\n%s\n", vstr);
	//makegrid(argv[1], limit);
}