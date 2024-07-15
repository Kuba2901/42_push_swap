/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:45:42 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 16:58:02 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_small(t_stack *a, t_stack *b)
{
	int	len_a;
	
	len_a = get_stack_len(a);
	if (len_a == 3)
		sort_three(a);
	else if (len_a == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}