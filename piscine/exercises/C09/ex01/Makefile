# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 13:52:52 by joho              #+#    #+#              #
#    Updated: 2025/04/10 13:53:38 by joho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile Vars
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = $(wildcard ./srcs/*.c)
OBJECTS = ${SOURCES:.c=.o}
HEADERS = includes
LIBC = ar rcs
LIBR = ranlib

# Rules
.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJECTS}
			${LIBC} ${NAME} ${OBJECTS}
			${LIBR} ${NAME}
all: ${NAME}
clean:
		${RM} ${OBJECTS}
fclean: clean
		${RM} ${NAME}
re: fclean all