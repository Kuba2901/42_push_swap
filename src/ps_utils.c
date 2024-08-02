/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:41 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 19:59:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = INT_MAX;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	ps_free_stack(t_stack *stack)
{
	while (stack->size > 0)
		ps_stack_pop(stack);
}

int	ps_get_stack_len(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	ps_is_sorted(t_stack *stack)
{
	t_node	*node;
	int		max;

	max = stack->top->value;
	node = stack->top;
	while (node)
	{
		if (node->value < max)
			return (0);
		max = node->value;
		node = node->next;
	}
	return (1);
}

int	ps_get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min;
	int		i;

	current = stack->top;
	min_index = 0;
	min = stack->top->value;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = i;
		}
		i++;
		current = current->next;
	}
	return (min_index);
}
