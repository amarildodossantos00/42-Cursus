CC = cc
CFLAGS = -Wall -Wextra -Werror
FILE = src/main.c
INCLUDES = include/philo.h
OBJS = $(FILE:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
