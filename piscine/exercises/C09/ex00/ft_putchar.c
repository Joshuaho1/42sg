/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:34:46 by joho              #+#    #+#             */
/*   Updated: 2025/03/21 14:14:26 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* This function writes a character to the standard output.
 * char c is passed to write function
 * (1, &c, 1) first 1 is used to std output, 
 * &c is the address of the character (a pointer), 
 * 1 is the size of the character which is 1 byte)
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
