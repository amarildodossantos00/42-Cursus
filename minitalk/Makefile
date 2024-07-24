# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdos-sa <amdos-sa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:10:43 by vcatete          #+#    #+#              #
#    Updated: 2024/07/24 12:14:27 by amdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS	= -Wall -Werror -Wextra
RM      = rm -rf
NAME1	= server
NAME2	= client
OBJS	= ft_printf.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<
all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS)
	$(CC) $(CFLAGS) server.c $(OBJS) -o $(NAME1)

$(NAME2): $(OBJS)
	$(CC) $(CFLAGS) client.c $(OBJS) -o $(NAME2)



clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean
	$(MAKE) all
