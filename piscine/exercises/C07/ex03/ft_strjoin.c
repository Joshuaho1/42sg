/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:45:17 by joho              #+#    #+#             */
/*   Updated: 2025/04/10 19:44:14 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		if (strs != NULL)
			total_len += ft_strlen(strs[i]);
		else
			total_len += ft_strlen(NULL);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

char	*assign_str(char *fullstr, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		if (strs && strs[i])
		{
			j = 0;
			while (strs[i][j] != '\0')
				fullstr[k++] = strs[i][j++];
		}
		if (i < size - 1 && sep)
		{
			j = 0;
			while (sep[j] != '\0')
				fullstr[k++] = sep[j++];
		}
		i++;
	}
	fullstr[k] = '\0';
	return (fullstr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*fullstr;
	char	*empty;
	int		total_len;

	if (size == 0 || strs == NULL)
	{
		empty = malloc(1);
		if (empty)
			empty[0] = '\0';
		return (empty);
	}
	if (sep == NULL)
		sep = "";
	total_len = ft_length(size, strs, sep);
	fullstr = (char *) malloc((total_len + 1) * sizeof(char));
	if (!fullstr)
		return (NULL);
	return (assign_str(fullstr, size, strs, sep));
}

/*
#include <stdio.h>
int	main(void)
{
	char *strs[3];
	char *fullstr;
	char *sep;
	char space = ' ';

	sep = &space;
	strs[0] = "Hello";
	strs[1] = "im";
	strs[2] = "trump";

	fullstr = ft_strjoin(3, strs, sep);
	printf("%s\n", fullstr);
	free(fullstr);
	return (0);
}
*/
/*
#include <stdio.h>
int main(void)
{
    char *strs1[] = {"Hello", "world", "!"};
    char *sep1 = ", ";
    char *result1 = ft_strjoin(3, strs1, sep1);
    printf("Test 1: %s\n", result1);  // "Hello, world, !"
    free(result1);
    char *strs2[] = {"One"};
    char *sep2 = "---";
    char *result2 = ft_strjoin(1, strs2, sep2);
    printf("Test 2: %s\n", result2);  // "One"
    free(result2);
    char *strs3[] = {NULL, "test", NULL};
    char *sep3 = "-";
    char *result3 = ft_strjoin(3, strs3, sep3);
    printf("Test 3: %s\n", result3);  // "-test-"
    free(result3);
    char *result4 = ft_strjoin(0, NULL, NULL);
    printf("Test 4: %s\n", result4);  // ""
    free(result4);
    return 0;
}
*/