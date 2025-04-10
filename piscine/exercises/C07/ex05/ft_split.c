/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:01:31 by joho              #+#    #+#             */
/*   Updated: 2025/04/10 19:58:19 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (find_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (!find_sep(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !find_sep(str[i], charset))
		i++;
	return (i);
}

char	*add_word(char *str, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		word_len;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL || charset == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char) * (count_words(str, charset) + 1));
	if (arr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (find_sep(str[i], charset))
			i++;
		word_len = ft_strlen_sep(&str[i], charset);
		if (word_len)
			arr[j++] = add_word(&str[i], word_len);
		i += word_len;
		word_len = 0;
	}
	arr[i] = 0;
	return (arr);
}
