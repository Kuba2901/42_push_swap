/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:06 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:06:59 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void push(t_stack *stack, int value)
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

void	push_to(t_stack *src, t_stack *dst)
{
    int	value;

    if (src->size == 0)
		return;
	value = pop(src);
    push(dst, value);
}