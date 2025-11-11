/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:27:26 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 18:26:40 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"
# include <stdbool.h>

int		main(int argc, char **argv);

// Build Stack
t_list	*build_stack(char **argv, bool argc_2);
int		valid_digit(char *s);
int		has_dupes(t_list *stack, long n);
long	ft_atol(const char *str);

// Free and Errors
void	error_free(t_list **stack, char **argv, bool argc_2);
void	free_split(char **arr);
void	free_all(t_list **stack);

// Sorting
int		stack_sorted(t_list *stack);
void	tiny_sort(t_list **a);
t_list	*find_high(t_list *stack);
void	finish_r(t_list **stack, t_list *top, char name);
void	set_node(t_list *a, t_list *b);
void	current_pos(t_list *stack);
void	set_cost(t_list *a, t_list *b);
void	set_cheapest(t_list *b);
t_list	*find_cheap(t_list	*stack);
t_list	*find_small(t_list *list);
void	push_swap(t_list **a, t_list **b);
void	five_n(t_list **a, t_list **b);

// Moves
// Swap
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

// Rotate
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);

// Reverse Rotate
void	rra(t_list **head);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

// Push
void	pb(t_list **a, t_list **b);
void	pa(t_list **b, t_list **a);

#endif