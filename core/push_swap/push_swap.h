/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:27:26 by joho              #+#    #+#             */
/*   Updated: 2025/10/16 02:08:10 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include "libft.h"

int		main(int argc, char **argv);
char	**parse_nums(int argc, char **argv);
int		check_nums(char **nums, long *inums);
int		valid_digit(char *s);
int		has_dupes(long *arr, int n);
void	free_split(char **arr);

#endif