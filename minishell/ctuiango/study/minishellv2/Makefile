NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = -lreadline -lhistory

SRC = src/main.c\
	src/file.c\
	src/filev2.c\
	src/filev3.c\
	src/var_ambient.c\
	src/count_args.c\
	src/execute.c\
	src/redic.c\
	src/redicv2.c\
	src/execute_pipe.c\
	src/builtins/commands.c\
	src/builtins/echo.c\
	src/builtins/ft_export.c\
	src/builtins/ft_unset.c\
	src/builtins/utils_exp.c\
	src/expand_exit_status.c\
	src/ft_expand_var.c\
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
	libx/ft_split_red.c\
	libx/ft_memset.c\
	libx/ft_space.c\
	libx/ft_substr.c\
	libx/ft_strtrim.c\
	libx/ft_split_args.c\
	libx/ft_strlcpy.c\
	libx/ft_count_words.c\
	libx/ft_itoa.c\
	libx/ft_memmove.c\
	libx/ft_strlcat.c\
	libx/ft_isalpha.c\
	libx/ft_isdigit.c\
	libx/ft_split_del.c\

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

