/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/10/15 16:47:44 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	char	**nums;
	char	**moves;
	long	**inums;
	int		status;

	status = 0;
	nums = parse_nums(argc, **argv);
	status = check_nums(nums, inums);
	if (!status)
		return (ft_printf("Error\n"), 1);
	build_list();
	sort();
	moves = print_mov();
	return (moves);
}

char	**parse_nums(int argc, char **argv)
{
	char	**nums;
	char	*joined;
	int		i;

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
	return (nums);
}

int	check_nums(char **nums, long **inums)
{
	int		count;
	long	val;
	int		i;

	count = 0;
	i = 0;
	while (nums[count])
		count++;
	*inums = ft_calloc(count, sizeof(long));
	if (!*inums)
		return (0);
	while (nums[i])
	{
		if (!valid_digit(nums[i]))
			return (0);
		val = ft_atoi(nums[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (0);
		(*inums)[i] = val; 
	}
	if (has_dupes(*inums, count))
		return (0);
	return (1);
}

int	valid_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_dupes(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}