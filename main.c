/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:52:55 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 19:44:53 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	ps_init_stacks(&stack_a, &stack_b);
	if (ps_detect_errors(ac, av, &stack_a))
		exit(0);
	if (!ps_is_sorted(&stack_a))
	{
		if (stack_a.size <= 5)
			ps_sort_small(&stack_a, &stack_b);
		else
			ps_complex_sort(&stack_a, &stack_b);
		ps_final_sort(&stack_a, &stack_b);
	}
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
