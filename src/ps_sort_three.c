/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:56:57 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/31 17:03:37 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ps_sort_three(t_stack *stack) {
    int a = stack->top->value;
    int b = stack->top->next->value;
    int c = stack->top->next->next->value;

    if (a > b && b < c && a < c)
		ps_sx(stack, SA);
    else if (a > b && b > c) {
		ps_sx(stack, SA);
		ps_rrx(stack, NULL, RRA);
    } else if (a > b && b < c && a > c) {
		ps_rx(stack, NULL, RA);
    } else if (a < b && b > c && a < c) {
		ps_sx(stack, SA);
        ps_rx(stack, NULL, RA);
    } else if (a < b && b > c && a > c)
		ps_rrx(stack, NULL, RRA);
}