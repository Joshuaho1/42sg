/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/11/05 01:06:17 by joho             ###   ########.fr       */
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
		ft_printf("unsorted\n");
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

int	stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// static void	swap(t_list *stack)
// {
	
// }