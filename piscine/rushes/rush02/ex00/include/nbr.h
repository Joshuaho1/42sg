/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlee <marlee@student.42student.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:27:58 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 22:09:45 by marlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

# include "dict.h"

typedef struct s_nbr_buffer
{
	char		**words;
	int			size;
}				t_nbr_buffer;

t_nbr_buffer	*new_nbr_buffer(void);
char			*nbr_str_to_substr(char *str, int start, int end);
char			*nbr_zeropadding(char digit, int nbr_of_zeros);
int				nbr_chunk(t_nbr_buffer *nbrbuf, t_dict *dict, char *str);
void			print_nbr_buffer(t_nbr_buffer *buffer);
void			add_nbr_buffer(t_nbr_buffer *buffer, char *word);
void			destory_nbr_buffer(t_nbr_buffer *buffer);

#endif
