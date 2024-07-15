/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:41 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 16:51:49 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void print_stacks(t_stack *a, t_stack *b)
{
    printf("\n--- Stack State ---\n");
    
    // Find the maximum size between both stacks
    int max_size = (a->size > b->size) ? a->size : b->size;
    
    // Find the maximum number width for formatting
    int max_width = 1;
    t_node *current = a->top;
    while (current) {
        int width = snprintf(NULL, 0, "%d", current->value);
        if (width > max_width) max_width = width;
        current = current->next;
    }
    current = b->top;
    while (current) {
        int width = snprintf(NULL, 0, "%d", current->value);
        if (width > max_width) max_width = width;
        current = current->next;
    }
    
    // Print the stacks
    printf("%-*s | %s\n", max_width + 2, "A", "B");
    printf("%.*s+%.*s\n", max_width + 2, "----------------------", max_width + 2, "----------------------");
    
    for (int i = 0; i < max_size; i++) {
        // Print stack A
        if (i < a->size) {
            current = a->top;
            for (int j = 0; j < i; j++) current = current->next;
            printf("%*d ", max_width, current->value);
        } else {
            printf("%*s ", max_width, "");
        }
        
        printf("| ");
        
        // Print stack B
        if (i < b->size) {
            current = b->top;
            for (int j = 0; j < i; j++) current = current->next;
            printf("%*d", max_width, current->value);
        }
        
        printf("\n");
    }
    
    printf("%.*s+%.*s\n", max_width + 2, "----------------------", max_width + 2, "----------------------");
    printf("\n");
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_operation(const char *op) {
    printf("%s\n", op);
}

int get_min(t_stack *stack) {
    t_node	*current;
    int		min;
	
	current = stack->top;
	min = INT_MAX;
    while (current) {
        if (current->value < min) {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

void free_stack(t_stack *stack) {
    while (stack->size > 0) {
        pop(stack);
    }
}

int	get_stack_len(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node) {
        i++;
        node = node->next;
    }
    return (i);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;
	int		max;

	max = stack->top->value;
	node = stack->top;
	while (node) {
        if (node->value < max)
			return (0);
		max = node->value;
        node = node->next;
    }
    return (1);
	
}