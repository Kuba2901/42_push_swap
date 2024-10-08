/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:55:26 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:23:21 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_reverse_rotate(t_stack *stack)
{
	t_node	*bottom_node;

	if (stack->size < 2)
		return ;
	bottom_node = stack->bottom;
	stack->bottom = bottom_node->prev;
	stack->bottom->next = NULL;
	bottom_node->next = stack->top;
	stack->top->prev = bottom_node;
	bottom_node->prev = NULL;
	stack->top = bottom_node;
}

void	ps_rrx(t_stack *a, t_stack *b, int code)
{
	if (code == RRA)
	{
		ps_reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if (code == RRB)
	{
		ps_reverse_rotate(b);
		ft_printf("rrb\n");
	}
	else if (code == RRR)
	{
		ps_reverse_rotate(a);
		ps_reverse_rotate(b);
		ft_printf("rrr\n");
	}
}
