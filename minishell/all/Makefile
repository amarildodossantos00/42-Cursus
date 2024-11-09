NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = -lreadline -lhistory

SRC = src/main.c\
      	src/file.c\
	libx/ft_strlen.c\

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

