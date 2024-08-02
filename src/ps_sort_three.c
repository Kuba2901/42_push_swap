/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:56:57 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 19:21:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_three(t_stack *stack) {
    int	a;
    int	b;
    int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
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