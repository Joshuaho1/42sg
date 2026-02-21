/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cd_path(char **argv, t_shell *sh)
{
	char	*path;

	if (!argv[1])
	{
		path = env_get(sh->env, "HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (NULL);
		}
		return (path);
	}
	if (ft_strncmp(argv[1], "-", 2) == 0)
	{
		path = env_get(sh->env, "OLDPWD");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (NULL);
		}
		ft_putendl_fd(path, 1);
		return (path);
	}
	return (argv[1]);
}

int	builtin_cd(char **argv, t_shell *sh)
{
	char	*path;
	char	cwd[4096];

	path = get_cd_path(argv, sh);
	if (!path)
		return (1);
	if (getcwd(cwd, sizeof(cwd)))
		env_set(&sh->env, "OLDPWD", cwd);
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)))
		env_set(&sh->env, "PWD", cwd);
	return (0);
}
