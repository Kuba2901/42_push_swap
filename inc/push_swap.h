/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:08:26 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:16:20 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <limits.h>
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
# define RA_RB 50
# define RA_RRB 51
# define RRA_RB 52

typedef struct s_node_push_instructions
{
	int	cost;
	int	*instructions;
}	t_node_push_instructions;

typedef struct s_node
{
	int				value;
	int				final_index;
	int				sa;
	int				sb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_instructions
{
	int	code;
	int	cost;
}	t_instructions;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
	t_node			*min;
	t_instructions	min_instructions;
}	t_stack;

void			ps_init_stacks(t_stack *a, t_stack *b);
int				ps_detect_errors(int ac, char **av, t_stack *a);
void			ps_printf_fd(int fd, char *str);
int				ps_is_valid_integer(const char *str);
int				ps_has_duplicates(t_stack *stack);
int				ps_choose_sorting_operation(t_stack *stack);
void			ps_complex_sort(t_stack *a, t_stack *b);
void			ps_final_sort(t_stack *a, t_stack *b);
int				ps_stack_pop(t_stack *stack);
void			ps_stack_push(t_stack *stack, int value);
void			ps_px(t_stack *a, t_stack *b, int code);
void			ps_push_to(t_stack *src, t_stack *dst);
void			ps_swap(t_stack *stack);
void			ps_sx(t_stack *stack, int code);
void			ps_rotate(t_stack *stack);
void			ps_rx(t_stack *a, t_stack *b, int code);
void			ps_reverse_rotate(t_stack *stack);
void			ps_rrx(t_stack *a, t_stack *b, int code);
void			ps_sort_three(t_stack *stack);
int				ps_get_min(t_stack *stack);
void			ps_free_stack(t_stack *stack);
int				ps_get_stack_len(t_stack *stack);
void			ps_sort_four(t_stack *a, t_stack *b);
int				ps_is_sorted(t_stack *stack);
void			ps_sort_small(t_stack *a, t_stack *b);
void			ps_sort_five(t_stack *a, t_stack *b);
int				ps_get_min_index(t_stack *stack);
void			ps_sort_int_array(int *arr, int arr_size);
int				*ps_dup_stack(t_stack *stack);
void			ps_assign_indexes(t_stack *a, int *arr);
void			ps_assign_push_cost(t_stack *a, t_stack *b);
void			ps_push_out_of_sequence(t_stack *a, t_stack *b);
t_instructions	calculate_total_cost(t_node *node);
void			push_cheapest(t_stack *a, t_stack *b);
void			ps_assign_instructions_data(t_instructions *instruction,
					int cost_rrr, int cost_ra_rrb, int cost_rra_rb);
int				ps_get_max_index(t_stack *a);
int				min_index(t_stack *a);
int				ps_find_num_index(int *arr, int arr_size, int num);
#endif
