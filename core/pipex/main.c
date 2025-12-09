/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:56:23 by joho              #+#    #+#             */
/*   Updated: 2025/12/09 16:07:40 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_path(char **envp);
static int	pipe_init(char **av, char **envp);
static void	child(char **av, char **envp, int *fd);
static void	parent(char **av, char **envp, int *fd);

int	main(int ac, char **av, char **envp)
{
	check_path(envp);
	if (ac == 5)
		return (pipe_init(av, envp));
	else
		error("Usage is ./pipex file1 cmd1 cmd2 file2. \
			Use quotations for flags, ex: 'ls -l'\n");
}

static void	check_path(char **envp)
{
	int	i;
	int	path;

	i = 0;
	path = 0;
	while (envp[i] != NULL)
	{
		if ((ft_strnstr(envp[i], "PATH=", 5) != NULL) && (envp[i][5] != '\0'))
			path = 1;
		i++;
	}
	if (path == 0)
		error("Invalid PATH\n");
}

static int	pipe_init(char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		child(av, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		parent(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

static void	child(char **av, char **envp, int *fd)
{
	int	fd_infile;

	fd_infile = open(av[1], O_RDONLY);
	if (fd_infile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("pipex");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_infile, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_infile);
	exec(av[2], envp);
}

static void	parent(char **av, char **envp, int *fd)
{
	int	fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("pipex");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_outfile);
	exec(av[3], envp);
}
