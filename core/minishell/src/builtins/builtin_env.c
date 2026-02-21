/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *sh)
{
	t_env	*env;

	env = sh->env;
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	return (0);
}
