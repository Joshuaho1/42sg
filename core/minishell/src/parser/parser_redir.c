/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_type	get_redir_type(t_token_type type)
{
	if (type == TOK_REDIR_IN)
		return (REDIR_IN);
	if (type == TOK_REDIR_OUT)
		return (REDIR_OUT);
	if (type == TOK_APPEND)
		return (REDIR_APPEND);
	return (REDIR_HEREDOC);
}

int	parse_redir(t_token **tok, t_redir **rds)
{
	t_redir		*rd;
	t_token		*cur;

	cur = *tok;
	rd = malloc(sizeof(t_redir));
	if (!rd)
		return (0);
	rd->type = get_redir_type(cur->type);
	rd->next = NULL;
	*tok = cur->next;
	if (!*tok || (*tok)->type != TOK_WORD)
	{
		free(rd);
		return (0);
	}
	rd->file = ft_strdup((*tok)->value);
	*tok = (*tok)->next;
	redir_add(rds, rd);
	return (1);
}
