# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 17:54:04 by joamunoz          #+#    #+#              #
#    Updated: 2026/09/02 11:43:19 by joamunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCE_FILES = ft_printf.c ft_printf_dec.c ft_printf_hex.c

OBJECTS = ${SOURCE_FILES:.c=.o}

%.o: %.c ft_printf.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
