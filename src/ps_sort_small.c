/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:45:42 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/31 16:57:59 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ps_sort_small(t_stack *a, t_stack *b)
{
    int len_a = ps_get_stack_len(a);
    
    if (ps_is_sorted(a))
        return;
    if (len_a == 2)
        ps_sx(a, SA);
    else if (len_a == 3)
        ps_sort_three(a);
    else if (len_a == 4)
        ps_sort_four(a, b);
    else if (len_a == 5)
        ps_sort_five(a, b);
}

void ps_sort_four(t_stack *a, t_stack *b)
{
    int min_index = ps_get_min_index(a);
    
    if (min_index == 1)
        ps_rx(a, b, RA);
    else if (min_index == 2)
        ps_rx(a, b, RA), ps_rx(a, b, RA);
    else if (min_index == 3)
        ps_rrx(a, b, RRA);
    
    if (!ps_is_sorted(a))
    {
        ps_px(a, b, PB);
        ps_sort_three(a);
        ps_px(a, b, PA);
    }
}

void ps_sort_five(t_stack *a, t_stack *b)
{
    int min_index = ps_get_min_index(a);
    
    if (min_index == 1)
        ps_rx(a, b, RA);
    else if (min_index == 2)
        ps_rx(a, b, RA), ps_rx(a, b, RA);
    else if (min_index == 3)
        ps_rrx(a, b, RRA), ps_rrx(a, b, RRA);
    else if (min_index == 4)
        ps_rrx(a, b, RRA);
    
    if (!ps_is_sorted(a))
    {
        ps_px(a, b, PB);
        ps_sort_four(a, b);
        ps_px(a, b, PA);
    }
}