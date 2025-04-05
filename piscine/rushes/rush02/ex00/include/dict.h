/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:20:57 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 00:07:30 by joho             ###   ########.fr       */
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

int		dict_parse(t_dict *dict, char *str);
t_dict	new_dict(void);

#endif