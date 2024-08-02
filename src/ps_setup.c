/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:54:25 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 17:06:25 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

int	ps_detect_errors(int ac, char **av, t_stack *a)
{
	int	i;

	i = ac;
	while (--i > 0)
	{
		if (!ps_is_valid_integer(av[i])) {
			ps_printf_fd(STDERR_FILENO, "Error\n");
            ps_free_stack(a);
            return (1);
        }
        ps_stack_push(a, ft_atoi(av[i]));
	}
    if (ps_has_duplicates(a)) {
		ps_printf_fd(STDERR_FILENO, "Error\n");
        ps_free_stack(a);
        return (1);
    }
	return (0);
}