/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:08:51 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 17:08:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack **lst)
{
	int		i;
	int		mid;
	t_stack	*stack;

	i = 0;
	stack = *lst;
	mid = mid_stack(stack);
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->is_in_top = 1;
		else
			stack->is_in_top = 0;
		stack = stack->next;
		i++;
	}
}

void	prep_stack_a(t_stack **a)
{
	int	*pivots;
	int	size;

	size = ft_stack_size(*a);
	pivots = malloc(4 * sizeof(int));
	if (!pivots)
		return ;
	pivots = find_pivots(*a, size, pivots);
	set_cheapest_to_null(a);
	assign_segment(a, pivots);
	free(pivots);
}

void	prep_stack_b(t_stack **b, t_stack **a)
{
	index_in_stack(a);
	index_in_stack(b);
	find_target_b_in_a(*b, *a);
	target_cost(b, a);
	total_cost(*b, *a);
	set_cheapest_to_null(b);
	get_cheapest(b);
}
