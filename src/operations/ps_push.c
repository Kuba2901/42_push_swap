/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:06 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:05:42 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (stack->top)
		stack->top->prev = new_node;
	else
		stack->bottom = new_node;
	stack->top = new_node;
	stack->size++;
}

void	ps_push_to(t_stack *src, t_stack *dst)
{
	int	value;
	int	final_index;

	if (src->size == 0)
		return ;
	final_index = src->top->final_index;
	value = ps_stack_pop(src);
	ps_stack_push(dst, value);
	dst->top->final_index = final_index;
}

void	ps_px(t_stack *a, t_stack *b, int code)
{
	if (code == PA)
	{
		ps_push_to(b, a);
		print_operation("pa");
	}
	else if (code == PB)
	{
		ps_push_to(a, b);
		print_operation("pb");
	}
}
