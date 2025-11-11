/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:42:56 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 18:22:55 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	tiny_sort(t_list **a)
{
	t_list	*highest;

	highest = find_high(*a);
	if (highest == *a)
		ra(a);
	else if (highest == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	five_n(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		set_node(*a, *b);
		finish_r(a, find_small(*a), 'a');
		pb(a, b);
	}
}
