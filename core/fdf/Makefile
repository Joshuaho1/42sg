# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 23:32:05 by joho              #+#    #+#              #
#    Updated: 2025/12/08 22:38:45 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c read_map.c error_free.c projection.c init.c hooks.c color.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLIB_DIR	= ./minilibx-linux
MINILIBX	= $(MLIB_DIR)/libmlx_Linux.a

CC			= cc -g
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(MLIB_DIR)

NAME		= fdf

all:		$(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MLIB_DIR)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 
	@$(MAKE) clean -C $(MLIB_DIR) 
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


