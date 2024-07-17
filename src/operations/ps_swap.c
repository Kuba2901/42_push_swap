/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:53:59 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/17 16:30:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_swap(t_stack *stack)
{
    int	temp;
	int	final_index;

    if (stack->size < 2)
		return;
	final_index = stack->top->final_index;
	temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
	stack->top->next->final_index = final_index;
}

void	ps_sx(t_stack *stack, int code)
{
	ps_swap(stack);
	if (code == SA)
		print_operation("SA");
	else if (code == SB)
		print_operation("SB");
}