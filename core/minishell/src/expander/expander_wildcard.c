/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_wildcard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_wildcard(char *s)
{
	int	in_sq;
	int	in_dq;

	in_sq = 0;
	in_dq = 0;
	while (*s)
	{
		if (*s == '\'' && !in_dq)
			in_sq = !in_sq;
		else if (*s == '"' && !in_sq)
			in_dq = !in_dq;
		else if (*s == '*' && !in_sq && !in_dq)
			return (1);
		s++;
	}
	return (0);
}

static int	match(char *pat, char *str)
{
	if (!*pat && !*str)
		return (1);
	if (*pat == '*')
	{
		while (*pat == '*')
			pat++;
		if (!*pat)
			return (1);
		while (*str)
		{
			if (match(pat, str))
				return (1);
			str++;
		}
		return (0);
	}
	if (*pat == *str)
		return (match(pat + 1, str + 1));
	return (0);
}

static int	count_matches(char *pattern)
{
	DIR				*dir;
	struct dirent	*ent;
	int				n;

	n = 0;
	dir = opendir(".");
	if (!dir)
		return (0);
	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.' && match(pattern, ent->d_name))
			n++;
		ent = readdir(dir);
	}
	closedir(dir);
	return (n);
}

char	**expand_wildcard(char *pattern)
{
	DIR				*dir;
	struct dirent	*ent;
	char			**result;
	int				n;
	int				i;

	n = count_matches(pattern);
	if (n == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (NULL);
	dir = opendir(".");
	i = 0;
	ent = readdir(dir);
	while (ent)
	{
		if (ent->d_name[0] != '.' && match(pattern, ent->d_name))
			result[i++] = ft_strdup(ent->d_name);
		ent = readdir(dir);
	}
	closedir(dir);
	result[i] = NULL;
	return (result);
}
