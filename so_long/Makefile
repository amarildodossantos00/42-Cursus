CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
WAY = minilibx-linux
MINILBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
FILE = main.c src/ft_strdup.c  src/get_map.c src/ft_strcat.c
OBJS = ${FILE:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		make -C ${WAY}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MINILBX}
		clear

clean:
		rm -f ${OBJS}
		make clean -C ${WAY}

fclean: clean
		rm -rf ${NAME}
		clear

re: fclean all

.PHONY: all clean fclean re
