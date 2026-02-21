/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_string(char *s, t_shell *sh)
{
	return (expand_quotes(s, sh));
}

static void	add_expanded(char **res, int *j, char *exp, char *orig)
{
	char	**wc;
	int		k;

	if (has_wildcard(orig) && !ft_strchr(orig, '\'')
		&& !ft_strchr(orig, '"'))
	{
		wc = expand_wildcard(exp);
		if (wc)
		{
			k = 0;
			while (wc[k])
			{
				res[*j] = wc[k];
				(*j)++;
				k++;
			}
			free(wc);
			free(exp);
			return ;
		}
	}
	res[*j] = exp;
	(*j)++;
}

char	**expand_args(char **argv, int argc, t_shell *sh)
{
	char	**result;
	char	*exp;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * (argc * 10 + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < argc)
	{
		exp = expand_string(argv[i], sh);
		add_expanded(result, &j, exp, argv[i]);
		i++;
	}
	result[j] = NULL;
	return (result);
}
