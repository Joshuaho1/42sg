/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*lex_redir(char *s, int *i)
{
	if (s[*i] == '<' && s[*i + 1] == '<')
	{
		*i += 2;
		return (token_new(TOK_HEREDOC, ft_strdup("<<")));
	}
	if (s[*i] == '>' && s[*i + 1] == '>')
	{
		*i += 2;
		return (token_new(TOK_APPEND, ft_strdup(">>")));
	}
	if (s[*i] == '<')
	{
		(*i)++;
		return (token_new(TOK_REDIR_IN, ft_strdup("<")));
	}
	(*i)++;
	return (token_new(TOK_REDIR_OUT, ft_strdup(">")));
}

static t_token	*lex_operator(char *s, int *i)
{
	if (s[*i] == '|' && s[*i + 1] == '|')
	{
		*i += 2;
		return (token_new(TOK_OR, ft_strdup("||")));
	}
	if (s[*i] == '|')
	{
		(*i)++;
		return (token_new(TOK_PIPE, ft_strdup("|")));
	}
	if (s[*i] == '&' && s[*i + 1] == '&')
	{
		*i += 2;
		return (token_new(TOK_AND, ft_strdup("&&")));
	}
	if (s[*i] == '(')
	{
		(*i)++;
		return (token_new(TOK_LPAREN, ft_strdup("(")));
	}
	(*i)++;
	return (token_new(TOK_RPAREN, ft_strdup(")")));
}

static t_token	*lex_one(char *s, int *i)
{
	if (s[*i] == '<' || s[*i] == '>')
		return (lex_redir(s, i));
	if (is_special_char(s[*i]))
		return (lex_operator(s, i));
	return (token_new(TOK_WORD, extract_word(s, i)));
}

t_token	*lexer(char *input)
{
	t_token	*lst;
	t_token	*tok;
	int		i;

	lst = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
		{
			i++;
			continue ;
		}
		tok = lex_one(input, &i);
		if (!tok)
		{
			token_free(lst);
			return (NULL);
		}
		token_add(&lst, tok);
	}
	return (lst);
}
