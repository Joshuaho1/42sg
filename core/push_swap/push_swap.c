/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:46:24 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 18:25:57 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	current_pos(*a);
	current_pos(*b);
}

static void	rr_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	current_pos(*a);
	current_pos(*b);
}

void	finish_r(t_list **stack, t_list *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheap(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		r_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rr_both(a, b, cheapest);
	finish_r(b, cheapest, 'b');
	finish_r(a, cheapest->target, 'a');
	pa(b, a);
}

void	push_swap(t_list **a, t_list **b)
{
	int		len_a;
	t_list	*smallest;

	len_a = ft_lstsize(*a);
	if (len_a == 5)
		five_n(a, b);
	else
	{
		while (len_a-- > 3)
			pb(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		set_node(*a, *b);
		move_nodes(a, b);
	}
	current_pos(*a);
	smallest = find_small(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
