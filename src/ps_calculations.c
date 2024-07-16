/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 17:50:20 by jnenczak         ###   ########.fr       */
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
		if (node_a->final_index < node_b->final_index)
			break ;
		i++;
		node_a = node_a->next;
	}
	// TODO: Verify these
	node_b->ra = i;
	node_b->rra = a->size - i;
	node_b->rb = node_b_pos;
	node_b->rrb = b->size - node_b_pos;
}

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	node = b->top;
	i = 0;
	node = b->top;
	while (node)
	{
		assign_node_cost(a, b, node, i);
		printf("Node num (%d) <--cost ra--> (%d)\n", i, node->ra);
		node = node->next;
		i++;
	}
}

// static int is_max(t_stack *a, t_node *node_b)
// {
// 	t_node	*node_a;

// 	node_a = a->top;
// 	while (node_a)
// 	{
// 		if (node_a->final_index > node_b->final_index)
// 			return (0);
// 		node_a = node_a->next;
// 	}
// 	return (1);
// }

// static int is_min(t_stack *a, t_node *node_b)
// {
// 	t_node	*node_a;

// 	node_a = a->top;
// 	while (node_a)
// 	{
// 		if (node_a->final_index < node_b->final_index)
// 			return (0);
// 		node_a = node_a->next;
// 	}
// 	return (1);
// }