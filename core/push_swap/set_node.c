/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:48:47 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 18:28:10 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_pos(t_list *stack)
{
	int	i;
	int	midpoint;

	i = 0;
	if (stack == NULL)
		return ;
	midpoint = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= midpoint)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	target_node(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target;
	long	best_match_val;

	while (b)
	{
		best_match_val = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_val)
			{
				best_match_val = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_val == LONG_MAX)
			b->target = find_small(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_cost(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->cost = b->current_pos;
		if (!(b->above_median))
			b->cost = len_b - (b->current_pos);
		if (b->target->above_median)
			b->cost += b->target->current_pos;
		else
			b->cost += len_a - (b->target->current_pos);
		b = b->next;
	}
}

void	set_cheapest(t_list *b)
{
	long	best_match_val;
	t_list	*best_match;

	if (b == NULL)
		return ;
	best_match_val = LONG_MAX;
	while (b)
	{
		if (b->cost < best_match_val)
		{
			best_match_val = b->cost;
			best_match = b;
		}
		b = b->next;
	}
	best_match->cheapest = true;
}

void	set_node(t_list *a, t_list *b)
{
	current_pos(a);
	current_pos(b);
	target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
