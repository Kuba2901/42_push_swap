/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/17 17:51:46 by jnenczak         ###   ########.fr       */
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
	node_b->rrb = b->size - node_b_pos - 1;
}

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	i = 0;
	node = b->top;
	while (node)
	{
		assign_node_cost(a, b, node, i);
		printf("Assigned cost of (%d) from B to be (ra - %d, rra - %d, rb - %d, rrb - %d)\n", node->value, node->ra, node->rra, node->rb, node->rrb);
		printf("Total cost: %d\n", calculate_total_cost(node));
		node = node->next;
		i++;
	}
}

int calculate_total_cost(t_node *node)
{
    int cost_rr;
    int cost_rrr;
    int cost_ra_rrb;
    int cost_rra_rb;
    int min_cost;

	cost_rr = node->ra + node->rb;
	cost_rrr = node->rra + node->rrb;
	cost_ra_rrb = node->ra + node->rrb;
	cost_rra_rb = node->rra + node->rb;
	min_cost = cost_rr;
    if (cost_rrr < min_cost) min_cost = cost_rrr;
    if (cost_ra_rrb < min_cost) min_cost = cost_ra_rrb;
    if (cost_rra_rb < min_cost) min_cost = cost_rra_rb;

    return (min_cost);
}