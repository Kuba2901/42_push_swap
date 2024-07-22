/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/22 16:51:23 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	assign_node_cost(t_stack *a, t_stack *b, t_node *node_b, int node_b_pos)
{
	t_node	*node_a;
	int		i;

	node_a = a->top;
	i = 0;
	while (node_a)
	{
		if (node_a->final_index > node_b->final_index)
			break ;
		i++;
		node_a = node_a->next;
	}
	// TODO: Verify these
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
	print_operation("STACKS BEFORE PUSHING CHEAPEST");
	print_stacks(a, b);
	printf("Cheapest num: %d <-> cost: %d and code: %d\n", min->value, b->min_instructions.cost, b->min_instructions.code);
	if (b->min_instructions.code == RR)
	{
		printf("CODE: RR\n");
		printf("Instructions - ra: %d <-> rb: %d\n", min->ra, min->rb);
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
    int				cost_rrr;
    int				cost_ra_rrb;
    int				cost_rra_rb;
	t_instructions	instructions;
	
	instructions.code = RR;
	instructions.cost = node->ra + node->rb;
	cost_rrr = node->rra + node->rrb;
	cost_ra_rrb = node->ra + node->rrb;
	cost_rra_rb = node->rra + node->rb;
    if (cost_rrr < instructions.cost)
	{
		instructions.code = RRR;
		instructions.cost = cost_rrr;
	}
    if (cost_ra_rrb < instructions.cost)
	{
		instructions.code = RA_RRB;
		instructions.cost = cost_ra_rrb;
	}
    if (cost_rra_rb < instructions.cost)
	{
		instructions.code = RRA_RB;
		instructions.cost = cost_rra_rb;
	}
    return (instructions);
}