/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:00 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 16:58:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void insertion_sort(t_stack *a, t_stack *b, int n)
// {
//     if (n <= 1)
//         return;
//     if (n == 2) {
//         if (a->top->value > a->top->next->value) {
//             swap(a);
//             print_operation("sa");
//         }
//         return;
//     }
//     if (n == 3) {
//         sort_three(a);
//         return;
//     }

//     // For more than 3 elements
//     int min = get_min(a);
//     while (a->size > 3) {
//         if (a->top->value == min) {
//             push_to(a, b);
//             print_operation("pb");
//             min = get_min(a);
//         } else {
//             rotate(a);
//             print_operation("ra");
//         }
//     }
//     sort_three(a);
//     while (b->size > 0) {
//         int to_insert = pop(b);
//         while (a->size > 0 && a->top->value < to_insert) {
//             rotate(a);
//             print_operation("ra");
//         }
//         push(a, to_insert);
//         print_operation("pa");

//         // Rotate back to the smallest element
//         while (a->top->value != min) {
//             rotate(a);
//             print_operation("ra");
//         }
//     }
// }

// static int	ps_find_min_index(t_list *elem)
// {
// 	int		min;
// 	int		index;
// 	int		i;

// 	min = ps_elem_value(elem);
// 	index = 0;
// 	i = 0;
// 	while (elem)
// 	{
// 		if (ps_elem_value(elem) < min)
// 		{
// 			min = ps_elem_value(elem);
// 			index = i;
// 		}
// 		elem = elem->next;
// 		i++;
// 	}
// 	return (index);
// }

// static int	ps_find_max_index(t_list *elem)
// {
// 	int		max;
// 	int		index;
// 	int		i;

// 	max = ps_elem_value(elem);
// 	index = 0;
// 	i = 0;
// 	while (elem)
// 	{
// 		if (ps_elem_value(elem) > max)
// 		{
// 			max = ps_elem_value(elem);
// 			index = i;
// 		}
// 		elem = elem->next;
// 		i++;
// 	}
// 	return (index);
// }


static int	get_min_index(t_stack *stack)
{
	t_node	*current;
    int		min_index;
    int		min;
    int		i;
	
	current = stack->top;
	min_index = 0;
	min = stack->top->value;
	i = 0;
    while (current)
	{
        if (current->value < min) {
            min = current->value;
            min_index = i;
        }
		i++;
        current = current->next;
    }
    return (min_index);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	if (is_sorted(a))
		return;
	min_index = get_min_index(a);
	if (min_index == 1)
	{
		rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2)
	{
		while (min_index-- > 0)
		{
			rotate(a);
			print_operation("RA");
		}
	}
	else
	{
		reverse_rotate(a);
		print_operation("RA");
	}
	if (is_sorted(a))
		return;
	push_to(a, b);
	print_operation("PB");
	sort_three(a);
	push_to(b, a);
	print_operation("PA");
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = get_min_index(a);
	if (min_index == 1)
	{
		rotate(a);
		print_operation("RA");
	}
	else if (min_index == 2 || min_index == 3)
	{
		while (min_index-- > 0)
		{
			rotate(a);
			print_operation("RA");
		}
	}
	else
	{
		reverse_rotate(a);
		print_operation("RRA");
	}
	if (is_sorted(a))
		return ;
	push_to(a, b);
	print_operation("PB");
	sort_four(a, b);
	push_to(b, a);
	print_operation("PA");
}