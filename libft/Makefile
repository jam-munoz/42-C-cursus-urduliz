# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 17:54:04 by joamunoz          #+#    #+#              #
#    Updated: 2026/08/30 02:30:11 by joamunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SOURCE_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c

BONUS_SOURCE_FILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			 ft_lstlast.c ft_lstmap.c ft_lstnew.c  ft_lstsize.c

OBJECTS = ${SOURCE_FILES:.c=.o}
BONUS_OBJECTS = ${BONUS_SOURCE_FILES:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

all: ${NAME}

bonus:	${NAME} ${BONUS_OBJECTS}
	${AR} ${NAME} ${BONUS_OBJECTS}

clean:
	${RM} ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
