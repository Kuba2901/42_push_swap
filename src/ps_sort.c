/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:00:46 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:08:16 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_stack *a, t_stack *b)
{
    if (a->size <= 3) {
        sort_three(a);
    } else if (a->size <= 5) {
        insertion_sort(a, b, a->size);
    } else {
        quicksort_partition(a, b, a->size);
    }
}