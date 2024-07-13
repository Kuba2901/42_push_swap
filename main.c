#include <push_swap.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    t_stack stack_a = {NULL, NULL, 0};
    t_stack stack_b = {NULL, NULL, 0};

    // Parse and validate input
    for (int i = argc - 1; i > 0; i--) {
        if (!is_valid_integer(argv[i])) {
            fprintf(stderr, "Error: Invalid input '%s'\n", argv[i]);
            free_stack(&stack_a);
            return 1;
        }
        push(&stack_a, atoi(argv[i]));
    }

    if (has_duplicates(&stack_a)) {
        fprintf(stderr, "Error: Duplicate numbers found\n");
        free_stack(&stack_a);
        return 1;
    }

    printf("Initial state:\n");
    print_stacks(&stack_a, &stack_b);

    // Sort the stack
    sort(&stack_a, &stack_b);

    printf("Final state:\n");
    print_stacks(&stack_a, &stack_b);

    // Verify if the stack is sorted
    t_node *current = stack_a.top;
    int is_sorted = 1;
    while (current && current->next) {
        if (current->value > current->next->value) {
            is_sorted = 0;
            break;
        }
        current = current->next;
    }

    if (is_sorted) {
        printf("The stack is correctly sorted.\n");
    } else {
        printf("Error: The stack is not correctly sorted.\n");
    }

    // Clean up
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}

