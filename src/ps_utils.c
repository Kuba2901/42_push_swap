/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:41 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:09:12 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_median(t_stack *stack, int n)
{
    int		*arr;
    t_node	*current;

	arr = malloc(n * sizeof(int));
	current = stack->top;
    for (int i = 0; i < n; i++) {
        arr[i] = current->value;
        current = current->next;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int median = arr[n / 2];
    free(arr);
    return median;
}

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
    int min = INT_MAX;
    t_node *current = stack->top;
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