/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:00:46 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/01 19:52:20 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_choose_sorting_operation(t_stack *stack)
{
	int	min_index;

	min_index = ps_get_min_index(stack);
	if (min_index > (stack->size / 2))
		return (RRA);
	return (RA);
}

void	ps_final_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size + 10;
	if (ps_choose_sorting_operation(a) == RA)
	{
		while (!ps_is_sorted(a) && i--)
			ps_rx(a, b, RA);
	}
	else
	{
		while (!ps_is_sorted(a) && i--)
			ps_rrx(a, b, RRA);
	}
}

void	ps_complex_sort(t_stack *a, t_stack *b)
{
	int	*arr;

	arr = ps_dup_stack(a);
	ps_sort_int_array(arr, a->size);
	ps_assign_indexes(a, arr);
	ps_push_out_of_sequence(a, b);
	ps_sort_small(a, b);
	while (b->size)
	{
		ps_assign_push_cost(a, b);
		push_cheapest(a, b);
	}
	free(arr);
}