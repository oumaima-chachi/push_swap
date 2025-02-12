
SRCS = exit_utils.c parsing.c parsing_utils.c\
	push_swap.c push_swap_operations.c\
	r_rotate_operations.c rotate_operations.c\
	short_sorts.c short_sorts_utils.c stack_utils.c\
	string_utils.c\

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
