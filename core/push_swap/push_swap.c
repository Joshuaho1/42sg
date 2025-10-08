/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/10/08 14:42:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	parse_nums(argc, **argv);
	return (0);
}

char	**parse_nums(int argc, char **argv)
{
	char	**nums;
	char	*joined;
	int	i;
	
	if (argc < 2)
		exit(1);
	i = 1;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (i < argc)
		joined = ft_strjoin(joined, argv[i++]);
	nums = ft_split(joined, ' ');
	free(joined);
	check_nums(nums);
	return(nums);
}

check_nums(char **nums)
{
	int	i;

	i = 0;
	while (i < nums)
}