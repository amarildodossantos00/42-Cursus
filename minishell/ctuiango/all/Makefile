NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = -lreadline -lhistory

SRC = src/main.c\
      	src/file.c\
	src/get_variables.c\
	src/liberar.c\
	libx/ft_strlen.c\
	libx/ft_strncmp.c\
	src/commands.c\
	src/echo.c\
	libx/ft_strchr.c\
	libx/ft_strdup.c\
	libx/ft_strcmp.c\
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

