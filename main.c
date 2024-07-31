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

int main(int argc, char *argv[]) {
    t_stack	stack_a;
    t_stack	stack_b;

    if (argc < 2)
		return (0);
	ps_init_stacks(&stack_a, &stack_b);
    // Parse and validate input
    for (int i = argc - 1; i > 0; i--) {
        if (!ps_is_valid_integer(argv[i])) {
            fprintf(stderr, "Error: Invalid input '%s'\n", argv[i]);
            ps_free_stack(&stack_a);
            return 1;
        }
        ps_stack_push(&stack_a, atoi(argv[i]));
    }

    if (ps_has_duplicates(&stack_a)) {
        fprintf(stderr, "Error: Duplicate numbers found\n");
        ps_free_stack(&stack_a);
        return 1;
    }
	int	*arr = ps_dup_stack(&stack_a);
	ps_sort_int_array(arr, stack_a.size);
	ps_assign_indexes(&stack_a, arr);
	ps_push_out_of_sequence(&stack_a, &stack_b);
	ps_sort_small(&stack_a, &stack_b);
	while (stack_b.size)
	{
		ps_assign_push_cost(&stack_a, &stack_b);
		push_cheapest(&stack_a, &stack_b);
	}
	int	i = stack_a.size + 10;
	if (choose_sorting_operation(&stack_a) == RA)
	{
		while (!ps_is_sorted(&stack_a) && i--)
			ps_rx(&stack_a, &stack_b, RA);
	}
	else
	{
		while (!ps_is_sorted(&stack_a) && i--)
			ps_rrx(&stack_a, &stack_b, RRA);
	}
    if (ps_is_sorted(&stack_a)) {
        printf("The stack is correctly sorted.\n");
    } else {
        printf("Error: The stack is not correctly sorted.\n");
    }
	print_stacks(&stack_a, &stack_b);
    ps_free_stack(&stack_a);
    ps_free_stack(&stack_b);
	free(arr);
    return 0;
}

