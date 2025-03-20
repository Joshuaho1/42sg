/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:48:39 by joho              #+#    #+#             */
/*   Updated: 2025/03/20 23:48:39 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* This function prints the alphabet to the std output
    char alphabet is an array of characters that is passed to the write function
    write function then outputs it with length of 27 bytes
*/

void	ft_print_alphabet(void)
{
	char	alphabet[];

	alphabet[] = "abcdefghijklmnopqrstuvwxyz\n";
	write(1, alphabet, 27);
}
