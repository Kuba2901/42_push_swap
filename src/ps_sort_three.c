/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:56:57 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:08:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;
	
    first = stack->top->value;
    second = stack->top->next->value;
    third = stack->bottom->value;
    if (first > second && second < third && first < third) {
        swap(stack);
        print_operation("sa");
    } else if (first > second && second > third) {
        swap(stack);
        print_operation("sa");
        reverse_rotate(stack);
        print_operation("rra");
    } else if (first > second && second < third && first > third) {
        rotate(stack);
        print_operation("ra");
    } else if (first < second && second > third && first < third) {
        swap(stack);
        print_operation("sa");
        rotate(stack);
        print_operation("ra");
    } else if (first < second && second > third && first > third) {
        reverse_rotate(stack);
        print_operation("rra");
    }
}