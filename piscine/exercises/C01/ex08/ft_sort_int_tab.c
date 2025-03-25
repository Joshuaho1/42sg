/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:33:59 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 18:26:47 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	swapped;
	int	n;

	n = size;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		n--;
	}
}

/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <digits_without_spaces>\n", argv[0]);
        return (1);
    }

    int len = strlen(argv[1]);
    int *digits = malloc(len * sizeof(int));
    if (!digits)
        return (1); // Allocation failed

    // Convert each char to an integer
    for (int i = 0; i < len; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Error: Only digits (0-9) allowed.\n");
            free(digits);
            return (1);
        }
        digits[i] = argv[1][i] - '0'; // Convert char to int
    }

    // Sort the digits
    ft_sort_int_tab(digits, len);

    // Print the sorted digits
    printf("Sorted digits: ");
    for (int i = 0; i < len; i++)
        printf("%d", digits[i]);
    printf("\n");

    free(digits);
    return (0);
}
*/