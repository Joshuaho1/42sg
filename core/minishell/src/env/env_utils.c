/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(key) + 1) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	env_set(t_env **env, char *key, char *val)
{
	t_env	*cur;
	t_env	*node;

	cur = *env;
	while (cur)
	{
		if (ft_strncmp(cur->key, key, ft_strlen(key) + 1) == 0)
		{
			free(cur->value);
			cur->value = ft_strdup(val);
			return (cur->value != NULL);
		}
		cur = cur->next;
	}
	node = malloc(sizeof(t_env));
	if (!node)
		return (0);
	node->key = ft_strdup(key);
	node->value = ft_strdup(val);
	node->next = *env;
	*env = node;
	return (1);
}

int	env_unset(t_env **env, char *key)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	prev = NULL;
	while (cur)
	{
		if (ft_strncmp(cur->key, key, ft_strlen(key) + 1) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

int	env_size(t_env *env)
{
	int	n;

	n = 0;
	while (env)
	{
		n++;
		env = env->next;
	}
	return (n);
}

char	**env_to_array(t_env *env)
{
	char	**arr;
	char	*tmp;
	int		i;

	arr = malloc(sizeof(char *) * (env_size(env) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env)
	{
		tmp = ft_strjoin(env->key, "=");
		arr[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		if (!arr[i])
			return (free_split(arr), NULL);
		env = env->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
