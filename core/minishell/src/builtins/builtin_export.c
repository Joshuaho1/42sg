/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_id(char *s)
{
	int	i;

	if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
		return (0);
	i = 1;
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(env->value, 1);
		ft_putstr_fd("\"\n", 1);
		env = env->next;
	}
}

static int	export_one(char *arg, t_shell *sh)
{
	char	*eq;
	char	*key;

	eq = ft_strchr(arg, '=');
	if (!eq)
		return (0);
	key = ft_substr(arg, 0, eq - arg);
	if (!is_valid_id(key))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(key);
		return (1);
	}
	env_set(&sh->env, key, eq + 1);
	free(key);
	return (0);
}

int	builtin_export(char **argv, t_shell *sh)
{
	int	i;
	int	ret;

	if (!argv[1])
	{
		print_export(sh->env);
		return (0);
	}
	ret = 0;
	i = 1;
	while (argv[i])
	{
		if (export_one(argv[i], sh))
			ret = 1;
		i++;
	}
	return (ret);
}
