/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/23 15:05:10 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_min(t_stack *a, t_node *node_b)
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

int	is_max(t_stack *a, t_node *node_b)
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

int	max_index(t_stack *a)
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

static void	assign_node_cost(t_stack *a, t_stack *b, t_node *node_b, int node_b_pos)
{
	t_node	*node_a;
	int		i;

	node_a = a->top;
	i = 0;
	while (node_a)
	{
		if (is_min(a, node_b))
		{
			i = min_index(a);
			break ;
		}
		else if (is_max(a, node_b))
		{
			i = max_index(a);
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
	node_b->rra = a->size - i - 1;
	node_b->rb = node_b_pos;
	node_b->rrb = b->size - node_b_pos;
}

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	i = 0;
	node = b->top;
	b->min = b->top;
	b->min_instructions = calculate_total_cost(b->top);
	while (node)
	{
		assign_node_cost(a, b, node, i);
		t_instructions instructions = calculate_total_cost(node);
		if (instructions.cost < calculate_total_cost(b->min).cost)
		{
			b->min = node;
			b->min_instructions = instructions;
		}
		node = node->next;
		i++;
	}
}

void	push_cheapest(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = b->min;
	if (b->min_instructions.code == RR)
	{
		while (min->ra > 0 && min->rb > 0)
		{
			ps_rx(a, b, RR);
			min->ra--;
			min->rb--;
		}
		while (min->ra-- > 0)
			ps_rx(a, b, RA);
		while (min->rb-- > 0)
			ps_rx(a, b, RB);
	}
	else if (b->min_instructions.code == RRR)
	{
		while (min->rra > 0 && min->rrb > 0)
		{
			ps_rx(a, b, RRR);
			min->rra--;
			min->rrb--;
		}
		while (min->rra-- > 0)
			ps_rx(a, b, RRA);
		while (min->rrb-- > 0)
			ps_rx(a, b, RRB);
	}
	else if (b->min_instructions.code == RA_RRB)
	{
		while (min->ra-- > 0)
			ps_rx(a, b, RA);
		while (min->rrb-- > 0)
			ps_rx(a, b, RRB);
	}
	else if (b->min_instructions.code == RRA_RB)
	{
		while (min->rra-- > 0)
			ps_rx(a, b, RRA);
		while (min->rb-- > 0)
			ps_rx(a, b, RB);
	}
	ps_px(a, b, PA);
}

t_instructions calculate_total_cost(t_node *node)
{
    // int				cost_rrr;
    // int				cost_ra_rrb;
    // int				cost_rra_rb;
	t_instructions	instructions;
	
	instructions.code = RR;
	instructions.cost = node->ra + node->rb;
	// cost_rrr = node->rra + node->rrb;
	// cost_ra_rrb = node->ra + node->rrb;
	// cost_rra_rb = node->rra + node->rb;
    // if (cost_rrr < instructions.cost)
	// {
	// 	instructions.code = RRR;
	// 	instructions.cost = cost_rrr;
	// }
    // if (cost_ra_rrb < instructions.cost)
	// {
	// 	instructions.code = RA_RRB;
	// 	instructions.cost = cost_ra_rrb;
	// }
    // if (cost_rra_rb < instructions.cost)
	// {
	// 	instructions.code = RRA_RB;
	// 	instructions.cost = cost_rra_rb;
	// }
    return (instructions);
}