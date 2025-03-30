/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:28:34 by joho              #+#    #+#             */
/*   Updated: 2025/03/30 15:31:42 by joho             ###   ########.fr       */
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

int	visible(int *val, int grid[size][size], int size, int *colups, int *coldowns, int *rowlefts, int *rowrights)
{
	int	i;
	i = 0;

	while(val[i])
	{
		int row;
		int col;
		int	vis_count;
		int	max_height;
		int	k;

		row = i / size;
		col = i % size;
		grid[row][col] = val[i];

		if (colups[col] != 0)
		{
			vis_count = 1;
			max_height = grid[0][col];
			k = 1;
			while(k < size)
			{
				if (grid[k][col] > max_height)
				{
					vis_count++;
					max_height = grid[k][col];
				}
			}
			if (vis_count != colups[col])
				return (0);
		}
		if (coldowns[col] != 0)
		{
			vis_count = 1;
			max_height = grid[size - 1][col];
			k = size - 2;
			while (k >= 0)
			{
				if (grid[k][col] > max_height)
				{
					vis_count++;
					max_height = grid[k][col];
				}
				k--;
			}
			if (vis_count != coldowns[col])
				return (0);
		}
		if (rowlefts[row] != 0)
		{
			vis_count = 1;
			max_height = grid[row][0];
			k = 1;
			while (k < size)
			{
				if (grid[row][k] > max_height)
				{
					vis_count++;
					max_height = grid[row][k];
				}
				k++;
			}
			if (vis_count != rowlefts[row])
				return (0);
		}
		if (rowrights[row] != 0)
		{
			vis_count = 1;
			max_height = grid[row][size - 1];
			k = size - 2;
			while (k > 0)
			{
				if (grid[row][k] > max_height)
				{
					vis_count++;
					max_height = grid[row][k];
				}
				k--;
			}
			if (vis_count != rowrights[row])
				return (0);
		}
		i++;
	}	
	return (1);
}

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