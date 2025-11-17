# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 23:32:05 by joho              #+#    #+#              #
#    Updated: 2025/11/17 16:24:37 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c read_map.c error_free.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc -g
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I$(LIBFT_DIR)

NAME		= fdf

all:		$(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) $(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


