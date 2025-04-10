/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:20:57 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 19:08:17 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict
{
	char	**keys;
	char	**values;
	int		size;
}	t_dict;

t_dict	new_dict(void);
int		dict_parse(t_dict *dict, char *str);
int		skip_to_word(char *str);
int		skip_to_num(char *str);
int		copy_nbr(char *dest, char *str);
int		copy_word(char *dest, char *str);
char	*dict_retrieve(t_dict *dict, char *key);
void	dict_create(t_dict *dict, char *key, char *value);

#endif
