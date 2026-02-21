/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	match(char *a, char *b)
{
	return (ft_strncmp(a, b, ft_strlen(b) + 1) == 0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (match(cmd, "echo") || match(cmd, "cd")
		|| match(cmd, "pwd") || match(cmd, "export")
		|| match(cmd, "unset") || match(cmd, "env")
		|| match(cmd, "exit"));
}

int	run_builtin(char **argv, t_shell *sh)
{
	if (match(argv[0], "echo"))
		return (builtin_echo(argv));
	if (match(argv[0], "cd"))
		return (builtin_cd(argv, sh));
	if (match(argv[0], "pwd"))
		return (builtin_pwd());
	if (match(argv[0], "export"))
		return (builtin_export(argv, sh));
	if (match(argv[0], "unset"))
		return (builtin_unset(argv, sh));
	if (match(argv[0], "env"))
		return (builtin_env(sh));
	if (match(argv[0], "exit"))
		return (builtin_exit(argv, sh));
	return (1);
}
