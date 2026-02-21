/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_redir_file(t_redir *rd)
{
	int	fd;

	fd = -1;
	if (rd->type == REDIR_IN || rd->type == REDIR_HEREDOC)
		fd = open(rd->file, O_RDONLY);
	else if (rd->type == REDIR_OUT)
		fd = open(rd->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (rd->type == REDIR_APPEND)
		fd = open(rd->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	apply_redirections(t_redir *rds)
{
	int	fd;
	int	target;

	while (rds)
	{
		fd = open_redir_file(rds);
		if (fd < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(rds->file, 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
		if (rds->type == REDIR_IN || rds->type == REDIR_HEREDOC)
			target = 0;
		else
			target = 1;
		dup2(fd, target);
		close(fd);
		rds = rds->next;
	}
	return (0);
}
