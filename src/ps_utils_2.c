/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:25:03 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/22 15:04:27 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partition(int *array, int start, int end)
{
    int pivot;
    int i;
    int j;

    pivot = array[end];
    i = start - 1;
    j = start;
    while (j <= end - 1)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[i + 1], &array[end]);
    return (i + 1);
}

static void quicksort(int *array, int start, int end)
{
    int pivot_index;
    if (start < end)
    {
        pivot_index = partition(array, start, end);
        quicksort(array, start, pivot_index - 1);
        quicksort(array, pivot_index + 1, end);
    }
}

static void print_int_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int *ps_dup_stack(t_stack *stack)
{
    int *ret;
    int i;
    t_node *current;

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

void	ps_sort_int_array(int *arr, int arr_size)
{
	quicksort(arr, 0, arr_size - 1);
	print_int_array(arr, arr_size);
}

static int	ps_find_num_index(int *arr, int arr_size, int num)
{
	int	i;

	i = -1;
	while (++i < arr_size)
	{
		if (arr[i] == num)
			return (i);
	}
	return (-1);
}

static void	print_stack_with_final_indexes(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		printf("Value: (%d), final index: (%d)\n", node->value, node->final_index);
		node = node->next;
	}
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
	print_stack_with_final_indexes(a);
}

void	ps_push_out_of_sequence(t_stack *a, t_stack *b)
{
	int		max;
	int		first;

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