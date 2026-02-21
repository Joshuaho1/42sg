/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*ast_new(t_node_type type)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	return (node);
}

void	ast_free(t_ast *node)
{
	if (!node)
		return ;
	if (node->cmd.argv)
		free_split(node->cmd.argv);
	redir_free(node->redirs);
	ast_free(node->left);
	ast_free(node->right);
	free(node);
}

void	redir_add(t_redir **lst, t_redir *new)
{
	t_redir	*cur;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	redir_free(t_redir *lst)
{
	t_redir	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->file);
		free(lst);
		lst = tmp;
	}
}

int	is_redir_token(t_token *tok)
{
	if (!tok)
		return (0);
	return (tok->type == TOK_REDIR_IN || tok->type == TOK_REDIR_OUT
		|| tok->type == TOK_APPEND || tok->type == TOK_HEREDOC);
}

int	syntax_error(char *msg, t_shell *sh)
{
	ft_putstr_fd("minishell: syntax error near `", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("'\n", 2);
	sh->exit_status = 2;
	return (0);
}
