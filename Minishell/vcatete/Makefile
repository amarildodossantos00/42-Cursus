# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcatete <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 09:13:08 by vcatete           #+#    #+#              #
#    Updated: 2024/10/16 09:13:11 by vcatete          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =  src/array_of_command.c \
	src/execute_command.c \
	src/ft_cd.c \
	src/ft_echo.c \
	src/ft_environ.c \
	src/ft_pipeline.c \
	src/ft_split.c \
	src/ft_strtok.c \
	src/main.c \
	src/redirect.c \
	src/redirect_init.c \
	src/ultis.c \
	src/ultis2.c \
	src/ultis3.c 

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
CFF = -lreadline -lncurses

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${CFF}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
