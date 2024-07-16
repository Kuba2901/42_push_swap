/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:56:57 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:04 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ps_sort_three(t_stack *stack) {
    int a = stack->top->value;
    int b = stack->top->next->value;
    int c = stack->top->next->next->value;

    if (a > b && b < c && a < c) {
        ps_sx(stack);
        print_operation("sa");
    } else if (a > b && b > c) {
        ps_sx(stack);
        print_operation("sa");
        ps_rrx(stack);
        print_operation("rra");
    } else if (a > b && b < c && a > c) {
        ps_rx(stack);
        print_operation("ra");
    } else if (a < b && b > c && a < c) {
        ps_sx(stack);
        print_operation("sa");
        ps_rx(stack);
        print_operation("ra");
    } else if (a < b && b > c && a > c) {
        ps_rrx(stack);
        print_operation("rra");
    }
}