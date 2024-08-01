/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/01 20:23:38 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_is_min(t_stack *a, t_node *node_b)
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

static int	ps_is_max(t_stack *a, t_node *node_b)
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

static void	ps_assign_node_cost(t_stack *a, t_stack *b, t_node *node_b, int node_b_pos)
{
	t_node	*node_a;
	int		i;

	node_a = a->top;
	i = 0;
	while (node_a)
	{
		if (ps_is_min(a, node_b))
		{
			i = min_index(a);
			break ;
		}
		else if (ps_is_max(a, node_b))
		{
			i = ps_get_max_index(a);
			break ;
		}
		else if (node_a->final_index > node_b->final_index)
		{
			if (node_a == a->top)
			{
				if (a->bottom->final_index < node_b->final_index)
					break ;
			}
			else if (node_a->prev->final_index < node_b->final_index)
				break ;
		}
		i++;
		node_a = node_a->next;
	}
	node_b->ra = i;
	if (i == 0)
		node_b->rra = 0;
	else
		node_b->rra = a->size - i;
	node_b->rb = node_b_pos;
	if (node_b_pos == 0)
		node_b->rrb = 0;
	else
		node_b->rrb = b->size - node_b_pos;
}

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node			*node;
	int				i;
	t_instructions	instructions;

	i = 0;
	node = b->top;
	ps_assign_node_cost(a, b, node, 0);
	b->min = node;
	b->min_instructions = calculate_total_cost(node);
	while (node)
	{
		ps_assign_node_cost(a, b, node, i);
		instructions = calculate_total_cost(node);
		if (instructions.cost < calculate_total_cost(b->min).cost)
		{
			b->min = node;
			b->min_instructions = instructions;
		}
		node = node->next;
		i++;
	}
}