#include <push_swap.h>

int	choose_sorting_operation(t_stack *stack)
{
	int	min_index;

	min_index = ps_get_min_index(stack);
	if (min_index > (stack->size / 2))
		return (RRA);
	return (RA);
}

void ps_init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

void	ps_printf_fd(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	ps_detect_errors(int ac, char **av, t_stack *a)
{
	int	i;

	i = ac;
	while (--i > 0)
	{
		if (!ps_is_valid_integer(av[i])) {
			ps_printf_fd(STDERR_FILENO, "Error: Some of the arguments are not integers\n");
            ps_free_stack(a);
            return (1);
        }
        ps_stack_push(a, ft_atoi(av[i]));
	}
    if (ps_has_duplicates(a)) {
		ps_printf_fd(STDERR_FILENO, "Error: Duplicate numbers found\n");
        ps_free_stack(a);
        return (1);
    }
	return (0);
}

void	ps_final_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size + 10;
	if (choose_sorting_operation(a) == RA)
	{
		while (!ps_is_sorted(a) && i--)
			ps_rx(a, b, RA);
	}
	else
	{
		while (!ps_is_sorted(a) && i--)
			ps_rrx(a, b, RRA);
	}
}

void	ps_complex_sort(t_stack *a, t_stack *b)
{
	int	*arr;

	arr = ps_dup_stack(a);
	ps_sort_int_array(arr, a->size);
	ps_assign_indexes(a, arr);
	ps_push_out_of_sequence(a, b);
	ps_sort_small(a, b);
	while (b->size)
	{
		ps_assign_push_cost(a, b);
		push_cheapest(a, b);
	}
	free(arr);
}

int main(int ac, char **av) {
    t_stack	stack_a;
    t_stack	stack_b;

    if (ac < 2)
		return (0);
	ps_init_stacks(&stack_a, &stack_b);
	if (ps_detect_errors(ac, av, &stack_a))
		exit(0);
	
	if (!ps_is_sorted(&stack_a))
	{
		if (stack_a.size <= 5)
			ps_sort_small(&stack_a, &stack_b);
		else
			ps_complex_sort(&stack_a, &stack_b);
		ps_final_sort(&stack_a, &stack_b);
	}
	// print_stacks(&stack_a, &stack_b);
    ps_free_stack(&stack_a);
    ps_free_stack(&stack_b);
    return (0);
}

