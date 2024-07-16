/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:00:46 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 17:24:53 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort(t_stack *a, t_stack *b) {
    if (a->size <= 5)
		ps_sort_small(a, b);
	else
		quick_sort_a(a, b, a->size);
    print_stacks(a, b);
}
