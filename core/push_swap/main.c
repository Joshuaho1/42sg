/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:21:39 by joho              #+#    #+#             */
/*   Updated: 2025/11/03 23:08:16 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long		*nums;
	t_list 		*a;

	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		nums = parse_nums(argv);
		free(argv);
	}
	else
		nums = parse_nums(argv + 1);
	if (!nums)
	{
		ft_printf("Error\n");
		free(nums);
		return (1);
	}
	a = build_stack(nums);
	// sort();
	// moves = print_mov();
	// return (moves);
	while (a)
	{
		printf("%p\n", a->content);
		a = a->next;
	}	
	free(nums);
	ft_lstclear(&a, free);
	return (0);
}

// int	check_args(int argc, char **argv, long *nums)
// {
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (0);
// 	if (argc == 2)
// 	{
// 		argv = ft_split(argv[1], ' ');
// 		nums = parse_nums(argv);
// 	}
// 	else
// 		nums = parse_nums(argv + 1);
// 	if (!nums)
// 	{
// 		ft_printf("Error\n");
// 		free(nums);
// 		return (1);
// 	}
// }

void	*build_stack(long *nums)
{
	t_list	*node;
	t_list	*stack;

	stack = NULL;
	node = NULL;
	stack = ft_lstnew(nums++);
	if (!stack)
		return (NULL);
	while (nums)
	{
		node = ft_lstnew(nums++);
		if (!node)
			return (NULL);
		ft_lstadd_back(&stack, node);
	}
	return (stack);
}

