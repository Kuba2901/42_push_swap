/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:02:09 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/15 17:26:13 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int *create_sorted_array(t_stack *stack, int len)
{
    if (!stack || !stack->top || stack->size == 0) {
        return NULL;
    }
    int *arr = malloc(sizeof(int) * len);
    if (!arr) {
        return NULL;
    }

    t_node *current = stack->top;
    int i = 0;
    while (current) {
        arr[i++] = current->value;
        current = current->next;
    }

    bubble_sort(arr, len);
    return arr;
}

int	find_median(t_stack *stack, int len)
{
	int	median;
	int	*array;

	array = create_sorted_array(stack, len);
	median = array[len / 2];
	free(array);
	return (median);
}

int	quick_sort_a(t_stack *a, t_stack *b, int len)
{
	int		median;
	int		len_copy;
	t_node	*node;

	median = find_median(a, len);
	len_copy = len;
	node = a->top;
	if (!len || !a->size)
		return (0);
	while (len_copy--)
	{
		if (node->value < median)
		{
			push_to(a, b);
			print_operation("PB");
		}
		else
		{
			rotate(a);
			print_operation("RA");
		}
	}
	quick_sort_a(a, b, len / 2);
	quick_sort_b(a, b, len / 2);
	return (0);
}

int	quick_sort_b(t_stack *a, t_stack *b, int len)
{
	int		median;
	int		len_copy;
	t_node	*node;

	median = find_median(b, len);
	len_copy = len;
	node = b->top;
	if (!len || !b->size)
		return (0);
	while (len_copy--)
	{
		if (node->value > median)
		{
			push_to(b, a);
			print_operation("PA");
		}
		else
		{
			rotate(b);
			print_operation("RB");
		}
	}
	quick_sort_a(a, b, len / 2);
	quick_sort_b(a, b, len / 2);
	return (0);
}