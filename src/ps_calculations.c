/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:12:01 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 17:25:43 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_assign_push_cost(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = b->top;
	while (node)
	{
		assign_node_cost(a, node);
		node = node->next;
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

static void	assign_node_cost(t_stack *a, t_node *node_b)
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
}