/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:59:39 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:07:58 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quicksort_partition(t_stack *a, t_stack *b, int n)
{
    int	partition_size;
    int	median;

    if (n <= 3) {
        sort_three(a);
        return;
    }
	median = get_median(a, n);
	partition_size = n / 2;
    for (int i = 0; i < partition_size; i++) {
        if (a->top->value < median) {
            push_to(a, b);
            print_operation("pb");
        } else {
            rotate(a);
            print_operation("ra");
        }
    }
    quicksort_partition(a, b, a->size);
    quicksort_partition(b, a, b->size);
    while (b->size > 0) {
        push_to(b, a);
        print_operation("pa");
    }
}