/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*env_new_node(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	return (node);
}

static int	parse_env_entry(char *entry, char **key, char **val)
{
	char	*eq;

	eq = ft_strchr(entry, '=');
	if (!eq)
		return (0);
	*key = ft_substr(entry, 0, eq - entry);
	*val = ft_strdup(eq + 1);
	if (!*key || !*val)
	{
		free(*key);
		free(*val);
		return (0);
	}
	return (1);
}

t_env	*env_init(char **envp)
{
	t_env	*head;
	t_env	*node;
	char	*key;
	char	*val;
	int		i;

	head = NULL;
	i = 0;
	while (envp && envp[i])
	{
		if (parse_env_entry(envp[i], &key, &val))
		{
			node = env_new_node(key, val);
			free(key);
			free(val);
			if (node)
			{
				node->next = head;
				head = node;
			}
		}
		i++;
	}
	return (head);
}

void	env_free(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}
