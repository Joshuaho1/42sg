/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/11/06 01:18:30 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*tmp;

	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = build_stack(argv + (argc != 2), argc == 2);
	if (!a)
		return (error_free(&a, argv, argc == 2), 1);
	if (!stack_sorted(a))
	{
		ra(&a);
	}
	// moves = print_mov();
	// return (moves);
	tmp = a;
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
	free_all(&a);
	return (0);
}

