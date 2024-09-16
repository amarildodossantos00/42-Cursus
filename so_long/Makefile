# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 12:06:55 by amdos-sa          #+#    #+#              #
#    Updated: 2024/09/16 08:31:19 by amdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

WAY = minilibx-linux
MINILIBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
SRC = src/main.c\
		src/get_map.c\
		src/aux_func1.c\
		src/ft_close.c\
		src/alocate_word.c\
		src/free_split.c\
		src/ft_strlen.c\
		src/deli.c\
		src/ft_split.c\
		src/get_next_line.c\
		src/render_map.c\
		src/move_p.c\
		src/validations_one.c\
		src/validation_two.c\
		src/validation_three.c\
		src/validation_four.c\
		src/set_images.c\
		src/ft_printf.c\
		src/game_print.c\

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C ${WAY}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${MINILIBX}
	clear

clean:
	rm -f ${OBJ}
	make clean -C ${WAY}
	clear

fclean: clean
	rm -rf ${NAME}
	clear

re: fclean all
	clear

.PHONY: all clean fclean re
