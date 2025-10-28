# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 14:36:23 by joho              #+#    #+#              #
#    Updated: 2025/10/16 00:59:46 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c push_swap_utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I$(LIBFT_DIR)

NAME		= push_swap

all:		$(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re

