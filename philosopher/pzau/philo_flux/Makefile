# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 12:17:22 by pzau              #+#    #+#              #
#    Updated: 2024/10/09 13:44:37 by amdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c\
      src/errors.c\
      src/ft_atoi.c\
	  src/init.c\
	  src/base_func.c\
	  src/last_all.c\
	  src/ft_time.c\
	  src/is_digit.c\
	  src/initial_aux.c\
	  src/monitor_philo.c\

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -r $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re




