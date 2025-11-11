/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:43:29 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 18:20:35 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_small(t_list *stack)
{
	t_list	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (smallest->value > stack->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_list	*find_cheap(t_list	*stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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
