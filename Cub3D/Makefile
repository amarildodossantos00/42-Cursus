# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 13:57:00 by amdos-sa          #+#    #+#              #
#    Updated: 2025/01/27 15:56:06 by amdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = main.c
OBJS = $(SRCS:.c=.o)
MINILIBX = minilibx-linux/libmlx.a

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(MINILIBX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MINILIBX) -lGL -lX11 -lXext -lXrandr -lm -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Iminilibx-linux -Iincludes -c $< -o $@

$(MINILIBX):
	@$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)
	@$(MAKE) clean -C minilibx-linux

re: fclean all
