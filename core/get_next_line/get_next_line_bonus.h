/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:03:10 by joho              #+#    #+#             */
/*   Updated: 2025/10/01 16:44:30 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	make_list(t_list **list, int fd);
int		found_newline(t_list *list);
void	add_buf(t_list **list, char *buf);
char	*get_line(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	prep_next(t_list **list);
t_list	*find_last_node(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif