NAME = push_swap
SRC = main.c src/operations/ps_pop.c src/operations/ps_push.c src/ps_quicksort.c src/operations/ps_reverse_rotate.c src/ps_sort.c src/operations/ps_rotate.c src/ps_sort_three.c src/operations/ps_swap.c src/ps_utils.c src/ps_error_checking.c src/ps_sort_small.c
OBJ = $(SRC:.c=.o)
INC_LIBFT_GNL = -Ilibft/inc_libft/ -Ilibft/inc_gnl/ -Ilibft/inc_ft_printf/
INC = -Iinc/ $(INC_LIBFT_GNL)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT_INCLUDE = -L./libft -lft
LIBS = $(LIBFT_INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean .c.o
