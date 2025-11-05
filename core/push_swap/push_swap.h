/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:27:26 by joho              #+#    #+#             */
/*   Updated: 2025/11/05 19:18:41 by joho             ###   ########.fr       */
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

// Algorithms
int		stack_sorted(t_list *stack);

// Free and Errors
void	error_free(t_list **stack, char **argv, bool argc_2);
void	free_split(char **arr);
void	free_all(t_list **stack);

// Moves
// Swap
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

// Rotate

// Reverse Rotate

// Push

#endif