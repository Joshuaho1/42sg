/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_subshell(t_ast *node, t_shell *sh)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		setup_signals_child();
		if (apply_redirections(node->redirs))
			exit(1);
		exit(execute_ast(node->left, sh));
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals_interactive();
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static int	execute_and(t_ast *node, t_shell *sh)
{
	int	ret;

	ret = execute_ast(node->left, sh);
	sh->exit_status = ret;
	if (ret == 0)
	{
		ret = execute_ast(node->right, sh);
		sh->exit_status = ret;
	}
	return (ret);
}

static int	execute_or(t_ast *node, t_shell *sh)
{
	int	ret;

	ret = execute_ast(node->left, sh);
	sh->exit_status = ret;
	if (ret != 0)
	{
		ret = execute_ast(node->right, sh);
		sh->exit_status = ret;
	}
	return (ret);
}

int	execute_ast(t_ast *node, t_shell *sh)
{
	if (!node)
		return (0);
	if (node->type == NODE_CMD)
		return (execute_cmd(node, sh));
	if (node->type == NODE_PIPE)
		return (execute_pipe(node, sh));
	if (node->type == NODE_AND)
		return (execute_and(node, sh));
	if (node->type == NODE_OR)
		return (execute_or(node, sh));
	if (node->type == NODE_SUBSHELL)
		return (execute_subshell(node, sh));
	return (1);
}
