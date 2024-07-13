/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:53:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/13 16:07:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void swap(t_stack *stack)
{
    int	temp;

    if (stack->size < 2)
		return;
	temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}