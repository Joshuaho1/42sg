/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 19:09:31 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	// t_list	*tmp;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = build_stack(argv + (argc != 2), argc == 2);
	if (!a)
		return (error_free(&a, argv, argc == 2), 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("%ld\n", tmp->value);
	// 	tmp = tmp->next;
	// }
	free_all(&a);
	return (0);
}

