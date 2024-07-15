/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:45:42 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 17:01:21 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_small(t_stack *a, t_stack *b)
{
	int	len_a;
	
	len_a = get_stack_len(a);
	if (len_a == 3)
		sort_three(a);
	else if (len_a == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	if (is_sorted(a))
		return;
	min_index = get_min_index(a);
	if (min_index == 1)
	{
		rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2)
	{
		while (min_index-- > 0)
		{
			rotate(a);
			print_operation("RA");
		}
	}
	else
	{
		reverse_rotate(a);
		print_operation("RA");
	}
	if (is_sorted(a))
		return;
	push_to(a, b);
	print_operation("PB");
	sort_three(a);
	push_to(b, a);
	print_operation("PA");
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = get_min_index(a);
	if (min_index == 1)
	{
		rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2 || min_index == 3)
	{
		while (min_index-- > 0)
		{
			rotate(a);
			print_operation("RA");
		}
	}
	else
	{
		reverse_rotate(a);
		print_operation("RRA");
	}
	if (is_sorted(a))
		return ;
	push_to(a, b);
	print_operation("PB");
	sort_four(a, b);
	push_to(b, a);
	print_operation("PA");
}