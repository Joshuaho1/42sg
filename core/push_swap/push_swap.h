/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:27:26 by joho              #+#    #+#             */
/*   Updated: 2025/11/04 01:00:41 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

int		main(int argc, char **argv);
long	*parse_nums(char **argv);
int		check_nums(char **nums, long *inums);
int		valid_digit(char *s);
int		has_dupes(t_list *stack, long n);
void	free_split(char **arr);
long	ft_atol(const char *str);
t_list	*build_stack(char **argv);
void	error_free(t_list *stack);

#endif