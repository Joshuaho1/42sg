/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:42:56 by joho              #+#    #+#             */
/*   Updated: 2025/11/06 23:20:40 by joho             ###   ########.fr       */
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

t_list	*find_high(t_list *stack)
{
	t_list	*high;
	
	high = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value > high->value)
			high = stack;
		stack = stack->next;
	}
	return (high);
}


