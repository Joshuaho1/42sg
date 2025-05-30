# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 12:57:03 by joho              #+#    #+#              #
#    Updated: 2025/05/30 18:21:41 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

flean: clean
	$(RM) $(NAME)

re: fclean $(NAME)