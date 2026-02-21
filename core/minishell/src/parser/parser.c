/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_command(t_token **tok, t_shell *sh)
{
	t_ast	*node;

	if (!*tok)
	{
		syntax_error("newline", sh);
		return (NULL);
	}
	if ((*tok)->type == TOK_LPAREN)
	{
		*tok = (*tok)->next;
		node = ast_new(NODE_SUBSHELL);
		if (!node)
			return (NULL);
		node->left = parse_expression(tok, sh);
		if (!node->left || !*tok || (*tok)->type != TOK_RPAREN)
		{
			ast_free(node);
			syntax_error(")", sh);
			return (NULL);
		}
		*tok = (*tok)->next;
		while (is_redir_token(*tok))
			if (!parse_redir(tok, &node->redirs))
				return (ast_free(node), NULL);
		return (node);
	}
	return (parse_simple_cmd(tok));
}

t_ast	*parse_pipeline(t_token **tok, t_shell *sh)
{
	t_ast	*left;
	t_ast	*node;

	left = parse_command(tok, sh);
	if (!left)
		return (NULL);
	while (*tok && (*tok)->type == TOK_PIPE)
	{
		*tok = (*tok)->next;
		node = ast_new(NODE_PIPE);
		if (!node)
			return (ast_free(left), NULL);
		node->left = left;
		node->right = parse_command(tok, sh);
		if (!node->right)
			return (ast_free(node), NULL);
		left = node;
	}
	return (left);
}

t_ast	*parse_expression(t_token **tok, t_shell *sh)
{
	t_ast		*left;
	t_ast		*node;
	t_node_type	type;

	left = parse_pipeline(tok, sh);
	if (!left)
		return (NULL);
	while (*tok && ((*tok)->type == TOK_AND || (*tok)->type == TOK_OR))
	{
		if ((*tok)->type == TOK_AND)
			type = NODE_AND;
		else
			type = NODE_OR;
		*tok = (*tok)->next;
		node = ast_new(type);
		if (!node)
			return (ast_free(left), NULL);
		node->left = left;
		node->right = parse_pipeline(tok, sh);
		if (!node->right)
			return (ast_free(node), NULL);
		left = node;
	}
	return (left);
}

t_ast	*parse_tokens(t_token **tok, t_shell *sh)
{
	t_ast	*ast;
	t_token	*cur;

	cur = *tok;
	ast = parse_expression(&cur, sh);
	if (cur != NULL)
	{
		syntax_error(cur->value, sh);
		ast_free(ast);
		return (NULL);
	}
	return (ast);
}
