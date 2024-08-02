/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:53:06 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:33:43 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_instructions	calculate_total_cost(t_node *node)
{
	t_instructions	instructions;
	int				cost_rrr;
	int				cost_ra_rrb;
	int				cost_rra_rb;

	instructions.cost = node->ra;
	instructions.code = RR;
	if (node->ra < node->rb)
		instructions.cost = node->rb;
	if (node->rra > node->rrb)
		cost_rrr = node->rra;
	else
		cost_rrr = node->rrb;
	cost_ra_rrb = node->ra + node->rrb;
	cost_rra_rb = node->rra + node->rb;
	ps_assign_instructions_data(&instructions, cost_rrr,
		cost_ra_rrb, cost_rra_rb);
	return (instructions);
}

int	min_index(t_stack *a)
{
	t_node	*temp;
	t_node	*min_node;
	int		min_index;
	int		i;

	temp = a->top;
	min_index = 0;
	min_node = a->top;
	i = 0;
	while (temp)
	{
		if (temp->final_index < min_node->final_index)
		{
			min_index = i;
			min_node = temp;
		}
		i++;
		temp = temp->next;
	}
	return (min_index);
}

int	ps_get_max_index(t_stack *a)
{
	t_node	*temp;
	t_node	*max_node;
	int		max_index;
	int		i;

	temp = a->top;
	max_index = 0;
	max_node = a->top;
	i = 0;
	while (temp)
	{
		if (temp->final_index > max_node->final_index)
		{
			max_index = i;
			max_node = temp;
		}
		i++;
		temp = temp->next;
	}
	if (max_index == a->size - 1)
		return (0);
	return (i);
}

int	ps_is_min(t_stack *a, t_node *node_b)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (temp->final_index < node_b->final_index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ps_is_max(t_stack *a, t_node *node_b)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (temp->final_index > node_b->final_index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
