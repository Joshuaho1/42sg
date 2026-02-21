/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**argv_grow(char **old, int count, char *word)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (count + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = old[i];
		i++;
	}
	new[count] = ft_strdup(word);
	new[count + 1] = NULL;
	free(old);
	return (new);
}

static int	is_cmd_token(t_token *tok)
{
	if (!tok)
		return (0);
	return (tok->type == TOK_WORD || is_redir_token(tok));
}

t_ast	*parse_simple_cmd(t_token **tok)
{
	t_ast	*node;

	node = ast_new(NODE_CMD);
	if (!node)
		return (NULL);
	while (is_cmd_token(*tok))
	{
		if (is_redir_token(*tok))
		{
			if (!parse_redir(tok, &node->redirs))
			{
				ast_free(node);
				return (NULL);
			}
		}
		else
		{
			node->cmd.argv = argv_grow(node->cmd.argv,
					node->cmd.argc, (*tok)->value);
			node->cmd.argc++;
			*tok = (*tok)->next;
		}
	}
	return (node);
}
