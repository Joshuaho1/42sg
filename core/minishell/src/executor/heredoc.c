/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_tmp_name(void)
{
	static int	n = 0;
	char		*num;
	char		*name;

	num = ft_itoa(n++);
	name = ft_strjoin("/tmp/.minishell_heredoc_", num);
	free(num);
	return (name);
}

static int	write_heredoc_line(int fd, char *line, t_shell *sh)
{
	char	*expanded;

	expanded = expand_string(line, sh);
	ft_putstr_fd(expanded, fd);
	ft_putstr_fd("\n", fd);
	free(expanded);
	return (0);
}

static int	read_heredoc(char *delim, char *tmpf, t_shell *sh)
{
	char	*line;
	int		fd;
	int		stdin_copy;

	fd = open(tmpf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	stdin_copy = dup(STDIN_FILENO);
	setup_signals_heredoc();
	while (1)
	{
		line = readline("> ");
		if (!line || g_signal == SIGINT)
		{
			free(line);
			break ;
		}
		if (ft_strncmp(line, delim, ft_strlen(delim) + 1) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc_line(fd, line, sh);
		free(line);
	}
	close(fd);
	dup2(stdin_copy, STDIN_FILENO);
	close(stdin_copy);
	if (g_signal == SIGINT)
		return (1);
	return (0);
}

static int	process_redir_heredoc(t_redir *rd, t_shell *sh)
{
	char	*tmpfile;

	tmpfile = make_tmp_name();
	if (!tmpfile)
		return (1);
	if (read_heredoc(rd->file, tmpfile, sh))
	{
		unlink(tmpfile);
		free(tmpfile);
		sh->exit_status = 130;
		return (1);
	}
	free(rd->file);
	rd->file = tmpfile;
	return (0);
}

int	handle_heredocs(t_ast *node, t_shell *sh)
{
	t_redir	*rd;

	if (!node)
		return (0);
	if (handle_heredocs(node->left, sh))
		return (1);
	if (handle_heredocs(node->right, sh))
		return (1);
	rd = node->redirs;
	while (rd)
	{
		if (rd->type == REDIR_HEREDOC)
		{
			if (process_redir_heredoc(rd, sh))
				return (1);
		}
		rd = rd->next;
	}
	return (0);
}
