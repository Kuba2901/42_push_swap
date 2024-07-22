/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:45:42 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/22 17:00:41 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_small(t_stack *a, t_stack *b)
{
	int	len_a;
	
	len_a = ps_get_stack_len(a);
	if (len_a == 3)
		ps_sort_three(a);
	else if (len_a == 4)
		ps_sort_four(a, b);
	else
		ps_sort_five(a, b);
}

void	ps_sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	if (ps_is_sorted(a))
		return;
	min_index = ps_get_min_index(a);
	if (min_index == 1)
	{
		ps_rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2)
	{
		while (min_index-- > 0)
		{
			ps_rotate(a);
			print_operation("RA");
		}
	}
	else if (min_index == 3)
	{
		ps_reverse_rotate(a);
		print_operation("RRA");
	}
	if (ps_is_sorted(a))
		return;
	ps_push_to(a, b);
	ps_sort_three(a);
	ps_push_to(b, a);
	print_operation("PA");
}

void	ps_sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = ps_get_min_index(a);
	printf("Min index: %d <-> %d\n", min_index, ps_get_min(a));
	if (min_index == 1)
	{
		ps_rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2 || min_index == 3)
	{
		while (min_index-- > 0)
		{
			ps_rotate(a);
			print_operation("RA");
		}
	}
	else
	{
		ps_reverse_rotate(a);
		print_operation("RRA");
	}
	if (ps_is_sorted(a))
		return ;
	ps_push_to(a, b);
	print_operation("PB");
	print_operation("PRINTING AFTER PUSH");
	print_stacks(a, b);
	ps_sort_four(a, b);
	print_operation("PRINTING AFTER 4 SORT");
	print_stacks(a, b);
}