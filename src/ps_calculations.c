/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:33:23 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_insertion_point(t_stack *a, t_node *node_b)
{
	t_node	*node_a;
	int		i;

	i = 0;
	if (ps_is_min(a, node_b))
		return (min_index(a));
	if (ps_is_max(a, node_b))
		return (ps_get_max_index(a));
	node_a = a->top;
	while (node_a)
	{
		if (node_a->final_index > node_b->final_index)
		{
			if (node_a == a->top \
				&& a->bottom->final_index < node_b->final_index)
				break ;
			if (node_a != a->top \
				&& node_a->prev->final_index < node_b->final_index)
				break ;
		}
		i++;
		node_a = node_a->next;
	}
	return (i);
}

static void	calculate_rotations(t_node *node_b, int i, int stack_size)
{
	node_b->ra = i;
	if (i == 0)
		node_b->rra = 0;
	else
		node_b->rra = stack_size - i;
}

static void	ps_assign_node_cost(t_stack *a, t_stack *b,
								t_node *node_b, int node_b_pos)
{
	int	i;

	i = find_insertion_point(a, node_b);
	calculate_rotations(node_b, i, a->size);
	node_b->rb = node_b_pos;
	if (node_b_pos == 0)
		node_b->rrb = 0;
	else
		node_b->rrb = b->size - node_b_pos;
}

static void	update_min_instructions(t_stack *b, t_node *node)
{
	t_instructions	instructions;

	instructions = calculate_total_cost(node);
	if (instructions.cost < calculate_total_cost(b->min).cost)
	{
		b->min = node;
		b->min_instructions = instructions;
	}
}

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	i = 0;
	node = b->top;
	ps_assign_node_cost(a, b, node, 0);
	b->min = node;
	b->min_instructions = calculate_total_cost(node);
	while (node)
	{
		ps_assign_node_cost(a, b, node, i);
		update_min_instructions(b, node);
		node = node->next;
		i++;
	}
}
