/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:47:58 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 16:00:13 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*old_head;
	int		len;

	len = ft_lstsize(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	old_head = *head;
	last = ft_lstlast(*head);
	*head = old_head->next;
	(*head)->prev = NULL;
	last->next = old_head;
	old_head->prev = last;
	old_head->next = NULL;
}

void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
