/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:21:01 by joho              #+#    #+#             */
/*   Updated: 2025/03/25 19:04:53 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp1;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		temp1 = tab[i];
		tab[i] = tab[j];
		tab[j] = temp1;
		i++;
		j--;
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
    ft_rev_int_tab(digits, len);

    // Print the sorted digits
    printf("Swapped digits: ");
    for (int i = 0; i < len; i++)
        printf("%d", digits[i]);
    printf("\n");

    free(digits);
    return (0);
}
*/