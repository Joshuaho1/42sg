# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 16:15:54 by joho              #+#    #+#              #
#    Updated: 2025/08/26 17:26:56 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SRCS	= libftprintf.c libftprintf_utils.c

OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	@ ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re