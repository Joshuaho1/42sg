/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/10/15 14:35:55 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	char	**nums;
	
	nums = parse_nums(argc, **argv);
	check_nums(nums);
	build_list();
	sort();
	print_sol();
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
	return(nums);
}
