/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:52:14 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 19:24:30 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_stack_pop(t_stack *stack)
{
    t_node	*top_node;
    int		value;
	
    if (stack->size == 0)
		return (INT_MIN);
	top_node = stack->top;
	value = top_node->value;
    stack->top = top_node->next;
    if (stack->top)
        stack->top->prev = NULL;
    else
        stack->bottom = NULL;
    free(top_node);
    stack->size--;
    return (value);
}
