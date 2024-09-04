CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/
CHECK = $(SRCS)checkers/
OPERAT = $(SRCS)operations/
ROTAT = $(SRCS)rotations/
FSTACK = $(SRCS)stack_functions/
UTILS = $(SRCS)utils/
FILE = $(UTILS)ft_atoi.c $(FSTACK)free_stack.c $(FSTACK)ft_stack_new.c $(FSTACK)ft_add_back.c $(UTILS)exit_error.c $(SRCS)algorithm.c $(CHECK)check_double_number.c $(CHECK)check_order.c $(CHECK)check_is_number.c $(OPERAT)operations_b.c $(SRCS)main.c $(UTILS)ft_printf.c $(OPERAT)operations_double.c $(UTILS)ft_strlen.c $(OPERAT)operations_a.c $(UTILS)ft_isdigit.c $(FSTACK)lst_max.c $(FSTACK)lst_min.c $(FSTACK)lst_size.c $(FSTACK)lst_last.c $(ROTAT)rotate_case_ab.c $(ROTAT)rotate_type.c $(ROTAT)rotate_case_ba.c $(FSTACK)find_place_a.c $(FSTACK)find_place_b.c $(FSTACK)find_index.c $(ROTAT)rotate_and_push.c $(SRCS)interpreter_args.c $(UTILS)ft_split.c $(UTILS)free_str.c
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
