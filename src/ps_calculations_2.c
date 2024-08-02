/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:23:11 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 19:53:25 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_push_cheapest_rr(t_stack *a, t_stack *b, t_node *min)
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

void	ps_push_cheapest_rrr(t_stack *a, t_stack *b, t_node *min)
{
	while (min->rra > 0 && min->rrb > 0)
	{
		ps_rrx(a, b, RRR);
		min->rra--;
		min->rrb--;
	}
	while (min->rra-- > 0)
		ps_rrx(a, b, RRA);
	while (min->rrb-- > 0)
		ps_rrx(a, b, RRB);
}

void	ps_push_cheapest_other(t_stack *a, t_stack *b, t_node *min)
{
	if (b->min_instructions.code == RA_RRB)
	{
		while (min->ra-- > 0)
			ps_rx(a, b, RA);
		while (min->rrb-- > 0)
			ps_rrx(a, b, RRB);
	}
	else if (b->min_instructions.code == RRA_RB)
	{
		while (min->rra-- > 0)
			ps_rrx(a, b, RRA);
		while (min->rb-- > 0)
			ps_rx(a, b, RB);
	}
}

void	push_cheapest(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = b->min;
	if (b->min_instructions.code == RR)
		ps_push_cheapest_rr(a, b, min);
	else if (b->min_instructions.code == RRR)
		ps_push_cheapest_rrr(a, b, min);
	else
		ps_push_cheapest_other(a, b, min);
	ps_px(a, b, PA);
}

void	ps_assign_instructions_data(t_instructions *instruction,
	int cost_rrr, int cost_ra_rrb, int cost_rra_rb)
{
	if (cost_rrr < instruction->cost)
	{
		instruction->code = RRR;
		instruction->cost = cost_rrr;
	}
	if (cost_ra_rrb < instruction->cost)
	{
		instruction->code = RA_RRB;
		instruction->cost = cost_ra_rrb;
	}
	if (cost_rra_rb < instruction->cost)
	{
		instruction->code = RRA_RB;
		instruction->cost = cost_rra_rb;
	}
}
