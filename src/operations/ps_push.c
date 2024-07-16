/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:06 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 15:22:25 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ps_stack_push(t_stack *stack, int value)
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

void	ps_px(t_stack *src, t_stack *dst)
{
    int	value;

    if (src->size == 0)
		return;
	value = ps_stack_pop(src);
    ps_stack_push(dst, value);
}