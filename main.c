#include <push_swap.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    t_stack stack_a;
    t_stack stack_b;

	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	stack_b.size = 0;

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
    while (!ps_is_sorted(&stack_a) && i--)
		ps_rx(&stack_a, &stack_b, RA);
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

