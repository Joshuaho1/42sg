/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:03:10 by joho              #+#    #+#             */
/*   Updated: 2025/09/02 15:34:04 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
int		found_newline(t_list *list);
char	*get_line(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	polish_list(t_list **list);
t_list	*find_last_node(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif