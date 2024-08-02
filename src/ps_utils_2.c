/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:25:03 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 20:15:57 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

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

static void	quicksort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		quicksort(array, start, pivot_index - 1);
		quicksort(array, pivot_index + 1, end);
	}
}

void	ps_sort_int_array(int *arr, int arr_size)
{
	quicksort(arr, 0, arr_size - 1);
}

int	ps_find_num_index(int *arr, int arr_size, int num)
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
