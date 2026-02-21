/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '&');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	skip_quotes(char *s, int i)
{
	char	quote;

	quote = s[i];
	i++;
	while (s[i] && s[i] != quote)
		i++;
	if (s[i])
		i++;
	return (i);
}

char	*extract_word(char *s, int *i)
{
	int		start;

	start = *i;
	while (s[*i] && !is_special_char(s[*i]) && s[*i] != ' '
		&& s[*i] != '\t')
	{
		if (is_quote(s[*i]))
			*i = skip_quotes(s, *i);
		else
			(*i)++;
	}
	return (ft_substr(s, start, *i - start));
}
