CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS= src/
FILE = $(SRCS)ft_atoi.c $(SRCS)stack.c $(SRCS)exit_error.c $(SRCS)algorithm.c $(SRCS)checkers.c $(SRCS)operations_b.c $(SRCS)main.c $(SRCS)ft_printf.c $(SRCS)operations_double.c $(SRCS)ft_strlen.c $(SRCS)operations_a.c $(SRCS)ft_isdigit.c $(SRCS)ft_lst.c $(SRCS)rotate_case_ab.c $(SRCS)rotate_type.c $(SRCS)rotate_case_ba.c $(SRCS)lst_find.c $(SRCS)rotate_and_push.c $(SRCS)interpreter_args.c $(SRCS)ft_split.c $(SRCS)free_str.c
INCLUDES = include/pswap.h
OBJS = $(FILE:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
