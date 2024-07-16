/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:25:03 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 16:09:08 by jnenczak         ###   ########.fr       */
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