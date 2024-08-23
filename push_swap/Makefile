CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/ft_atoi.c src/stack.c src/exit_error.c src/algorithm.c src/checkers.c src/operations_b.c src/main.c src/ft_printf.c src/operations_double.c src/ft_strlen.c src/operations_a.c src/ft_isdigit.c src/print_stack.c
INCLUDES = include/pswap.h
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
