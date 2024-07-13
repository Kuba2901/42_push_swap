/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:56:57 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 18:49:02 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_three(t_stack *stack) {
    int a = stack->top->value;
    int b = stack->top->next->value;
    int c = stack->top->next->next->value;

    if (a > b && b < c && a < c) {
        swap(stack);
        print_operation("sa");
    } else if (a > b && b > c) {
        swap(stack);
        print_operation("sa");
        reverse_rotate(stack);
        print_operation("rra");
    } else if (a > b && b < c && a > c) {
        rotate(stack);
        print_operation("ra");
    } else if (a < b && b > c && a < c) {
        swap(stack);
        print_operation("sa");
        rotate(stack);
        print_operation("ra");
    } else if (a < b && b > c && a > c) {
        reverse_rotate(stack);
        print_operation("rra");
    }
}