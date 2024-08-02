/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:55:20 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:01:58 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_printf_fd(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	*ps_dup_stack(t_stack *stack)
{
	int		*ret;
	int		i;
	t_node	*current;

	ret = malloc(sizeof(int) * ps_get_stack_len(stack));
	if (ret == NULL)
		exit(1);
	current = stack->top;
	i = 0;
	while (current)
	{
		ret[i++] = current->value;
		current = current->next;
	}
	return (ret);
}

void	ps_assign_indexes(t_stack *a, int *arr)
{
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		j = i;
		while (j)
		{
			j->final_index = ps_find_num_index(arr, a->size, j->value);
			j = j->next;
		}
		i = i->next;
	}
}

void	ps_push_out_of_sequence(t_stack *a, t_stack *b)
{
	int	max;
	int	first;

	max = a->top->value;
	first = max;
	ps_rx(a, b, RA);
	while (a->top && a->size > 5 && a->top->value != first)
	{
		if (a->top->value < max)
			ps_px(a, b, PB);
		else
		{
			max = a->top->value;
			ps_rx(a, b, RA);
		}
	}
}
