/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:43:40 by joho              #+#    #+#             */
/*   Updated: 2025/12/09 16:05:50 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*cmd_path(char *cmd, char **envp);
static void	exec_error(char **cmd_str, char *path);

void	exec(char *cmd, char **envp)
{
	char	**cmd_strs;
	char	*path;

	if (!cmd || cmd[0] == '\0')
		error("Empty command\n");
	cmd_strs = ft_split(cmd, ' ');
	if (!cmd_strs || !cmd_strs[0])
	{
		free_split(cmd_strs);
		error("Empty command\n");
	}
	path = cmd_path(cmd_strs[0], envp);
	if (!path)
	{
		free_split(cmd_strs);
		free(path);
		error("Command not found in PATH\n");
	}
	if (execve(path, cmd_strs, envp) == -1)
		exec_error(cmd_strs, path);
	free_split(cmd_strs);
	free(path);
}

static char	*cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**all_paths;
	char	*current_path;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		current_path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(current_path, cmd);
		free(current_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(all_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_split(all_paths);
	return (NULL);
}

void	error(char *msg)
{
	write(2, "Error:", 6);
	write(2, msg, ft_strlen(msg));
	exit(127);
}

static void	exec_error(char **cmd_str, char *path)
{
	free_split(cmd_str);
	free(path);
	error("Execution failed\n");
}