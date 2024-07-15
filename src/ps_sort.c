/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:00:46 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 16:53:03 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort(t_stack *a, t_stack *b) {
    if (a->size <= 5)
		ps_sort_small(a, b);
	else
		print_operation("TOO BIG");
    print_stacks(a, b);
}
