#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <limits.h>
# include <stdio.h> // TODO; Remove
# define ERROR_NO_ARGUMENTS 1
# define ERROR_NOT_INTEGERS 2
# define ERROR_INT_OVERFLOW 3
# define ERROR_CONTAINS_DUPLICATES 4
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define NUMBERS_VALID 0
# define RA 30
# define RB 31
# define RR 32
# define PA 33
# define PB 34
# define SA 35
# define SB 36
# define RRA 37
# define RRB 38
# define RRR 39


typedef struct s_node {
    int value;
	int	final_index;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack {
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

int		ps_stack_pop(t_stack *stack);
void	ps_stack_push(t_stack *stack, int value);
void	ps_push_to(t_stack *src, t_stack *dst);
void	ps_px(t_stack *a, t_stack *b, int code);
void	ps_swap(t_stack *stack);
void	ps_sx(t_stack *stack, int code);
void	ps_rotate(t_stack *stack);
void	ps_rx(t_stack *a, t_stack *b, int code);
void	ps_reverse_rotate(t_stack *stack);
void	ps_rrx(t_stack *a, t_stack *b, int code);
int		ps_is_valid_integer(const char *str);
int		ps_has_duplicates(t_stack *stack);
void	ps_sort_three(t_stack *stack);
void	ps_main_sort(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	print_operation(const char *op);
int		ps_get_min(t_stack *stack);
void	ps_free_stack(t_stack *stack);
int		ps_get_stack_len(t_stack *stack);
void	ps_sort_four(t_stack *a, t_stack *b);
int		ps_is_sorted(t_stack *stack);
void	ps_sort_small(t_stack *a, t_stack *b);
void	ps_sort_five(t_stack *a, t_stack *b);
int		ps_get_min_index(t_stack *stack);
void	ps_sort_int_array(int *arr, int arr_size);
int		*ps_dup_stack(t_stack *stack);
void	ps_assign_indexes(t_stack *a, int *arr);
#endif