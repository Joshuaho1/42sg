/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:51:32 by joho              #+#    #+#             */
/*   Updated: 2025/11/11 16:00:59 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*build_stack(char **argv, bool argc_2)
{
	t_list	*node;
	t_list	*stack;
	long	num;

	stack = NULL;
	while (*argv)
	{
		if (!valid_digit(*argv))
			return (ft_lstclear(&stack, free), NULL);
		num = ft_atol(*argv);
		if (num < INT_MIN || num > INT_MAX)
			return (ft_lstclear(&stack, free), NULL);
		if (has_dupes(stack, num))
			return (ft_lstclear(&stack, free), NULL);
		node = ft_lstnew(num);
		if (!node)
			return (ft_lstclear(&stack, free), NULL);
		ft_lstadd_back(&stack, node);
		argv++;
	}
	if (argc_2)
		free_split(argv);
	return (stack);
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

int	has_dupes(t_list *stack, long n)
{
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
