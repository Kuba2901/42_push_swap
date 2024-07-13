/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:07:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	insertion_sort(t_stack *a, t_stack *b, int n)
{
    if (n <= 3) {
        sort_three(a);
        return;
    }

    while (a->size > 3) {
        push_to(a, b);
        print_operation("pb");
    }
    sort_three(a);
    while (b->size > 0) {
        int to_insert = pop(b);
        print_operation("pa");
        while (a->size > 0 && a->top->value < to_insert) {
            push_to(a, b);
            print_operation("pb");
        }
        push(a, to_insert);
        while (b->size > 0 && b->top->value != to_insert) {
            push_to(b, a);
            print_operation("pa");
        }
    }
    while (a->top->value != get_min(a)) {
        rotate(a);
        print_operation("ra");
    }
}