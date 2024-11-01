# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:27:25 by cramos            #+#    #+#              #
#    Updated: 2024/10/28 13:44:16 by cramos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror
FLGS = -lreadline

files = files/main.c\

OBJ = $(files:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(FLGS)
clean:
	@rm -r $(OBJ)
fclean:
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@echo "All clean!"
re: fclean all

.PHONY: all clean fclean re
