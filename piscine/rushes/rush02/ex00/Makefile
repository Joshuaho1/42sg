# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 15:02:40 by marlee            #+#    #+#              #
#    Updated: 2025/04/08 16:09:43 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -g -Wall -Wextra -Werror -I./include
TARGET  = rush-02

SRCS    =	source/main.c \
			source/functions/ft_error.c \
			source/functions/ft_putchar.c \
			source/functions/ft_putstr.c \
			source/functions/ft_strcpy.c \
			source/functions/ft_strlen.c \
			source/functions/ft_strcmp.c \
			source/nbr/nbr_zeropadding.c \
			source/nbr/nbr_buffer.c \
			source/nbr/nbr_chunk.c \
			source/nbr/nbr_str_to_substr.c \
			source/files/read_file.c \
			source/check/check.c \
			source/dict/dict_create.c \
			source/dict/dict_ft.c \
			source/dict/dict_parse.c \
			source/dict/new_dict.c \
			source/dict/dict_retrieve.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
fclean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
