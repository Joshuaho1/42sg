/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:27:26 by joho              #+#    #+#             */
/*   Updated: 2025/11/03 16:30:34 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			val;
	struct s_stack	*front;
	struct s_stack	*back;
}	t_stack;

int		main(int argc, char **argv);
long	*parse_nums(char **argv);
int		check_nums(char **nums, long *inums);
int		valid_digit(char *s);
int		has_dupes(long *arr, int n);
void	free_split(char **arr);
long	ft_atol(const char *str);
void	*build_stack(long *nums);

#endif