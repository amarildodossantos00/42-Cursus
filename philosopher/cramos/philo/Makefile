# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 12:21:14 by cramos            #+#    #+#              #
#    Updated: 2024/10/04 12:27:24 by cramos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

SRC = 




OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	clear
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
	clear
re: fclean all

.PHONY: all clean fclean re
