/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 18:50:29 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void insertion_sort(t_stack *a, t_stack *b, int n)
{
    if (n <= 1)
        return;
    if (n == 2) {
        if (a->top->value > a->top->next->value) {
            swap(a);
            print_operation("sa");
        }
        return;
    }
    if (n == 3) {
        sort_three(a);
        return;
    }

    // For more than 3 elements
    int min = get_min(a);
    while (a->size > 3) {
        if (a->top->value == min) {
            push_to(a, b);
            print_operation("pb");
            min = get_min(a);
        } else {
            rotate(a);
            print_operation("ra");
        }
    }
    sort_three(a);
    while (b->size > 0) {
        int to_insert = pop(b);
        while (a->size > 0 && a->top->value < to_insert) {
            rotate(a);
            print_operation("ra");
        }
        push(a, to_insert);
        print_operation("pa");

        // Rotate back to the smallest element
        while (a->top->value != min) {
            rotate(a);
            print_operation("ra");
        }
    }
}