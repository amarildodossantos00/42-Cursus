NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = -lreadline -lhistory

SRC = src/main.c\
      	src/file.c\
	src/get_variables.c\
	src/liberar.c\
	src/execute.c\
	src/count_args.c\
	src/commands.c\
	src/echo.c\
	src/filter_commands.c\
	libx/ft_strlen.c\
	libx/ft_strncmp.c\
	libx/ft_strjoin.c\
	libx/ft_strcpy.c\
	libx/ft_strchr.c\
	libx/ft_strdup.c\
	libx/ft_strcmp.c\
	libx/ft_strtok.c\
	libx/sncat.c\
	libx/ft_split.c\

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(COMPILE)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re

