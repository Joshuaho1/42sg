/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*try_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	if (access(full, X_OK) == 0)
		return (full);
	free(full);
	return (NULL);
}

char	*find_command(char *cmd, t_shell *sh)
{
	char	*path_env;
	char	**dirs;
	char	*result;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = env_get(sh->env, "PATH");
	if (!path_env)
		return (NULL);
	dirs = ft_split(path_env, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		result = try_path(dirs[i], cmd);
		if (result)
			return (free_split(dirs), result);
		i++;
	}
	free_split(dirs);
	return (NULL);
}

static void	exec_error(char *cmd)
{
	struct stat	sb;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (ft_strchr(cmd, '/') && stat(cmd, &sb) == 0 && S_ISDIR(sb.st_mode))
		ft_putstr_fd(": Is a directory\n", 2);
	else if (ft_strchr(cmd, '/'))
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}

static void	child_exec(char **argv, t_shell *sh)
{
	char	*path;
	char	**envp;

	setup_signals_child();
	path = find_command(argv[0], sh);
	if (!path)
	{
		exec_error(argv[0]);
		if (ft_strchr(argv[0], '/'))
			exit(127);
		exit(127);
	}
	envp = env_to_array(sh->env);
	execve(path, argv, envp);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(126);
}

static int	run_external(char **argv, t_shell *sh, t_redir *rds)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		if (apply_redirections(rds))
			exit(1);
		child_exec(argv, sh);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals_interactive();
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		else if (WTERMSIG(status) == SIGINT)
			ft_putstr_fd("\n", 2);
		return (128 + WTERMSIG(status));
	}
	return (WEXITSTATUS(status));
}

int	execute_cmd(t_ast *node, t_shell *sh)
{
	char	**expanded;
	int		ret;

	if (!node->cmd.argv || !node->cmd.argv[0])
	{
		if (node->redirs)
			return (apply_redirections(node->redirs));
		return (0);
	}
	expanded = expand_args(node->cmd.argv, node->cmd.argc, sh);
	if (!expanded || !expanded[0])
	{
		free_split(expanded);
		return (0);
	}
	if (is_builtin(expanded[0]))
	{
		ret = apply_redirections(node->redirs);
		if (ret)
			return (free_split(expanded), ret);
		ret = run_builtin(expanded, sh);
		free_split(expanded);
		return (ret);
	}
	ret = run_external(expanded, sh, node->redirs);
	free_split(expanded);
	return (ret);
}
