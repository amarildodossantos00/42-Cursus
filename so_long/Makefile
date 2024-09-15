# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 12:06:56 by cramos            #+#    #+#              #
#    Updated: 2024/08/31 12:07:02 by cramos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

WAY = minilibx-linux

MINILBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

SRC = files/main.c\
		files/read_map.c\
		files/ft_split.c\
		files/auxilary.c\
		files/close_window.c\
		files/img.c\
		files/set_img.c\
		files/move_player.c\
		files/val_argum.c\
		files/vali_jogab.c\
		files/ft_flood_fill.c\
		ftprintf/ft_printf.c\
		ftprintf/ft_print.c\
		ftprintf/auxilary_func.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		make -C ${WAY}
		${CC} ${FLAGS} -o ${NAME} ${OBJS} ${MINILBX}
		clear

clean:
		rm -f ${OBJS}
		make clean -C ${WAY}

fclean: clean
		rm -rf ${NAME}
		clear
		
re: fclean all

.PHONY: all clean fclean re