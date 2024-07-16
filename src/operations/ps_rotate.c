/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:54:42 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 15:22:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_rx(t_stack *stack)
{
    t_node	*top_node;

    if (stack->size < 2)
		return;
	top_node = stack->top;
    stack->top = top_node->next;
    stack->top->prev = NULL;
    stack->bottom->next = top_node;
    top_node->prev = stack->bottom;
    top_node->next = NULL;
    stack->bottom = top_node;
}