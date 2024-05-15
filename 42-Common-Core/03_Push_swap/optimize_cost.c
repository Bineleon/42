/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:05:15 by neleon            #+#    #+#             */
/*   Updated: 2024/05/15 16:26:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	get_cheapest_by_segment(t_stack **a, int seg)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost && stack_a->segment == seg)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
}

void	assign_cost_in_a(t_stack **a)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(stack_a);
	index_in_stack(a);
	while (stack_a)
	{
		stack_a->total_cost = calculate_node_cost(stack_a, stack_len);
		stack_a = stack_a->next;
	}
}

void	set_cheapest_to_null(t_stack **lst)
{
	t_stack	*stack;

	stack = *lst;
	while (stack)
	{
		stack->is_cheapest = 0;
		stack = stack->next;
	}
}
