/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:49:58 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 16:47:07 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int	quick_select(int *arr, int low, int high, int k)
{
	int	index_pivot;

	if (low <= high)
	{
		index_pivot = partition(arr, low, high);
		if (index_pivot == k)
			return (arr[index_pivot]);
		else if (index_pivot < k)
			return (quick_select(arr, index_pivot + 1, high, k));
		else
			return (quick_select(arr, low, index_pivot - 1, k));
	}
	return (-1);
}

void	fill_arr(t_stack *stack, int **arr)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		(*arr)[i] = current->nb;
		current = current->next;
		i++;
	}
}

int	*find_pivots(t_stack *stack, int size, int *pivots)
{
	int	i;
	int	*values;

	i = -1;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	fill_arr(stack, &values);
	if (size > 100)
	{
		pivots[0] = quick_select(values, 0, size - 1, size / 5);
		pivots[1] = quick_select(values, 0, size - 1, (2 * size) / 5);
		pivots[2] = quick_select(values, 0, size - 1, (3 * size) / 5);
		pivots[3] = quick_select(values, 0, size - 1, (4 * size) / 5);
	}
	else
	{
		while (++i <= 3)
			pivots[i] = 0;
	}
	free(values);
	return (pivots);
}

void	assign_segment(t_stack **a, int *pivot)
{
	int		value;
	t_stack	*stack_a;

	stack_a = *a;
	value = stack_a->nb;
	while (stack_a)
	{
		value = stack_a->nb;
		if (value <= pivot[0])
			stack_a->segment = 1;
		else if (value <= pivot[1])
			stack_a->segment = 2;
		else if (value <= pivot[2])
			stack_a->segment = 3;
		else if (value <= pivot[3])
			stack_a->segment = 4;
		else
			stack_a->segment = 5;
		stack_a = stack_a->next;
	}
}
