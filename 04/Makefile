NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	adaptive.c \
		bench.c \
		build_normalized.c \
		check_repeat.c \
		complex.c \
		flag_search.c \
		free_stack.c \
		ft_atoi.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memset.c \
		ft_sqrt.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		is_almost_sorted.c \
		main.c \
		medium.c \
		mini_sort.c \
		normalize_args.c \
		push.c \
		reverse.c \
		rotate_only.c \
		rotate.c \
		simple.c \
		stack_init.c \
		swap.c

PRINTF_SRC =	ft_printf/ft_printf.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_putnbr.c \
				ft_printf/ft_putnbr_base.c \
				ft_printf/ft_putnbr_unsigned.c \
				ft_printf/ft_putpointer.c \
				ft_printf/ft_put_str.c \
				ft_printf/ft_strcpy.c

OBJ = $(SRC:.c=.o) $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
