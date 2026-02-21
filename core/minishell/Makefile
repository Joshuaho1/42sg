# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 10:56:16 by joho              #+#    #+#              #
#    Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/main.c \
			  src/signals.c \
			  src/lexer/lexer.c \
			  src/lexer/lexer_utils.c \
			  src/lexer/token.c \
			  src/parser/parser.c \
			  src/parser/parser_cmd.c \
			  src/parser/parser_redir.c \
			  src/parser/parser_utils.c \
			  src/expander/expander.c \
			  src/expander/expander_quotes.c \
			  src/expander/expander_wildcard.c \
			  src/executor/executor.c \
			  src/executor/executor_cmd.c \
			  src/executor/executor_pipe.c \
			  src/executor/executor_redir.c \
			  src/executor/heredoc.c \
			  src/builtins/builtins.c \
			  src/builtins/builtin_echo.c \
			  src/builtins/builtin_cd.c \
			  src/builtins/builtin_pwd.c \
			  src/builtins/builtin_export.c \
			  src/builtins/builtin_unset.c \
			  src/builtins/builtin_env.c \
			  src/builtins/builtin_exit.c \
			  src/env/env.c \
			  src/env/env_utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc -g
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I$(LIBFT_DIR) -Iinclude

NAME		= minishell

all:		$(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
