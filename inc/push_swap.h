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

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack {
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

int		pop(t_stack *stack);
void	push(t_stack *stack, int value);
void	push_to(t_stack *src, t_stack *dst);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(t_stack *stack);
int		is_valid_integer(const char *str);
int		has_duplicates(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	print_operation(const char *op);
int		get_min(t_stack *stack);
void	free_stack(t_stack *stack);
int		get_stack_len(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	ps_sort_small(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
#endif