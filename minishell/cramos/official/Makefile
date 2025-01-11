NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = -lreadline -lhistory

SRC = src/main.c\
	src/aux1.c\
	src/aux2.c\
	src/aux3.c\
	src/filev1.c\
	src/filev2.c\
	src/filev3.c\
	src/var_ambient.c\
	src/init_values.c\
	src/count_args.c\
	src/execute.c\
	src/ft_expand_var.c\
	src/expand_exit_status.c\
	src/expand_exit_status1.c\
	src/builtins/utils_exp.c\
	src/builtins/commands.c\
	src/builtins/commandsv1.c\
	src/builtins/echo.c\
	src/builtins/ft_export.c\
	src/builtins/ft_export_1.c\
	src/builtins/ft_unset.c\
	src/red_and_pipe/filev1.c\
	src/red_and_pipe/filev1_1.c\
	src/red_and_pipe/filev1_2.c\
	src/red_and_pipe/filev2.c\
	src/red_and_pipe/filev2_1.c\
	src/red_and_pipe/filev2_2.c\
	src/red_and_pipe/filev2_3.c\
	src/red_and_pipe/filev2_4.c\
	src/red_and_pipe/filev3.c\
	src/red_and_pipe/filev3_1.c\
	src/red_and_pipe/execute_pipe.c\
	src/red_and_pipe/execute_pipe_two.c\
	src/free/filev1.c\
	libx/ft_strlen.c\
	libx/ft_strncmp.c\
	libx/ft_strjoin.c\
	libx/ft_strcpy.c\
	libx/ft_strchr.c\
	libx/ft_strdup.c\
	libx/ft_strdupv2.c\
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
	libx/ft_strcat.c\
	libx/ft_isalnum.c\
	libx/ft_strncpy.c\
	libx/ft_strstr.c\
	libx/ft_atoi.c\
	libx/ft_trim.c\
	libx/ft_isspace.c\
	libx/ft_strnfill.c\
	libx/ft_split_args_aux.c\

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(COMPILE) -g

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re

