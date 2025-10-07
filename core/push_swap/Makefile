# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 14:36:23 by joho              #+#    #+#              #
#    Updated: 2025/10/07 15:44:39 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= blahblah.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= ./libft/libft.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -Ilibft

NAME		= push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
	@ ar rcs $(NAME) $(OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re

