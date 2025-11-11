/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:09:57 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 19:27:25 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_list **stack, char **argv, bool argc_2)
{
	write(2, "Error\n", 6);
	if (argc_2)
		free_split(argv);
	ft_lstclear(stack, free);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all(t_list **stack)
{
	ft_lstclear(stack, free);
}
