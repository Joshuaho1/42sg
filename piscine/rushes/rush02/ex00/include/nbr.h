/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:27:58 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 00:51:47 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

typedef struct s_nbr_buffer
{
	char	**words;
	int		size;
}	t_nbr_buffer;

t_nbr_buffer	*new_nbr_buffer(void);
int				nbr_chunk(t_nbr_buffer *nbrbuf, t_dict *dict, char *str);
static int		nbr_store(t_nbr_buffer *nbrbuf, t_dict *dict, char *str);
static int		nbr_tens(t_nbr_buffer *nbrbuf, t_dict *dict, char *str);
static int		nbr_hundreds(t_nbr_buffer *nbrbuf, t_dict *dict, char *str);

#endif
