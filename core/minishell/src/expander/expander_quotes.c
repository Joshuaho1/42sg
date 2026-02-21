/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char(char *s, char c)
{
	char	buf[2];
	char	*res;

	buf[0] = c;
	buf[1] = '\0';
	res = ft_strjoin(s, buf);
	free(s);
	return (res);
}

static char	*append_str(char *s, char *add)
{
	char	*res;

	if (!add)
		return (s);
	res = ft_strjoin(s, add);
	free(s);
	return (res);
}

static char	*expand_var(char *s, int *i, t_shell *sh)
{
	int		start;
	char	*key;
	char	*val;

	(*i)++;
	if (s[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->exit_status));
	}
	start = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_'))
		(*i)++;
	if (*i == start)
		return (ft_strdup("$"));
	key = ft_substr(s, start, *i - start);
	val = env_get(sh->env, key);
	free(key);
	if (val)
		return (ft_strdup(val));
	return (ft_strdup(""));
}

static char	*handle_single_q(char *res, char *s, int *i)
{
	(*i)++;
	while (s[*i] && s[*i] != '\'')
	{
		res = append_char(res, s[*i]);
		(*i)++;
	}
	if (s[*i])
		(*i)++;
	return (res);
}

char	*expand_quotes(char *s, t_shell *sh)
{
	char	*res;
	char	*var;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' )
			res = handle_single_q(res, s, &i);
		else if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
			{
				if (s[i] == '$')
				{
					var = expand_var(s, &i, sh);
					res = append_str(res, var);
					free(var);
				}
				else
					res = append_char(res, s[i++]);
			}
			if (s[i])
				i++;
		}
		else if (s[i] == '$')
		{
			var = expand_var(s, &i, sh);
			res = append_str(res, var);
			free(var);
		}
		else
			res = append_char(res, s[i++]);
	}
	return (res);
}
