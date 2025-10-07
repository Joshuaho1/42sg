/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/10/07 17:00:40 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	parse_num(argc, **argv);
	return (0);
}

int	parse_num(int argc, char **argv)
{
	int	i;
	
	if (argc < 2)
		exit(1);
	i = 1;
	while (i < argc)
	{
		
		i++;
	}
	
}