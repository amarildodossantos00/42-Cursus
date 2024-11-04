# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:52:21 by amdos-sa          #+#    #+#              #
#    Updated: 2024/11/04 11:48:37 by amdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/utils/sncat.c src/utils/ft_strtok.c src/execute.c src/controls.c
OBJ = $(SRC:.c=.o)
DELETE = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	clear
	@echo "Processando..."
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lreadline $(LIBFT) && echo "Compilado com sucesso!" || (echo "A compilação falhou."; exit 1)

$(LIBFT):
	@make -C $(LIBFT_DIR) >/dev/null

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(DELETE) $(OBJ)
	@make clean -C $(LIBFT_DIR) >/dev/null

fclean: clean
	@$(DELETE) $(NAME)
	@make fclean -C $(LIBFT_DIR) >/dev/null
	clear
	@echo "Limpeza feita com sucesso!"

re: fclean all

.PHONY: all clean fclean re
