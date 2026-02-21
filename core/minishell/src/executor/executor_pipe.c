/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static void	pipe_child_left(int *fd, t_ast *node, t_shell *sh)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	setup_signals_child();
	exit(execute_ast(node->left, sh));
}

static void	pipe_child_right(int *fd, t_ast *node, t_shell *sh)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	setup_signals_child();
	exit(execute_ast(node->right, sh));
}

int	execute_pipe(t_ast *node, t_shell *sh)
{
	int		fd[2];
	pid_t	pid_l;
	pid_t	pid_r;
	int		status;

	if (pipe(fd) < 0)
		return (1);
	pid_l = fork();
	if (pid_l == 0)
		pipe_child_left(fd, node, sh);
	pid_r = fork();
	if (pid_r == 0)
		pipe_child_right(fd, node, sh);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_l, NULL, 0);
	waitpid(pid_r, &status, 0);
	return (get_exit_status(status));
}
