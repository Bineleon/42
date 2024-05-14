/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:01:45 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 18:56:13 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	get_cheapest(t_stack **a)
{
	t_stack	*stack_a;
	t_stack	*cheapest;
	int		cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (cheapest)
		cheapest->is_cheapest = 1;
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

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*stack_a;

	stack_a = a;
	if (!stack_a)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->is_cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	target_cost(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	stack_len = ft_stack_size(*b);
	while (stack_a)
	{
		if (stack_a->target_node->is_in_top)
			stack_a->target_cost = stack_a->target_node->index;
		else
			stack_a->target_cost = stack_len - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

int	calculate_node_cost(t_stack *node, int stack_length)
{
	if (node->is_in_top)
		return (node->index);
	else
		return (stack_length - node->index);
}

int	ft_min(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

void	calculate_total_cost(t_stack *a, t_stack *b)
{
	int		stack_len_a;
	int		stack_len_b;
	t_stack	*stack_a;
	int		cost_a;
	int		cost_b;

	stack_len_a = ft_stack_size(a);
	stack_len_b = ft_stack_size(b);
	stack_a = a;
	while (stack_a)
	{
		cost_a = calculate_node_cost(stack_a, stack_len_a);
		cost_b = calculate_node_cost(stack_a->target_node, stack_len_b);
		if (stack_a->is_in_top == stack_a->target_node->is_in_top)
			stack_a->total_cost = cost_a + cost_b - ft_min(cost_a, cost_b);
		else
			stack_a->total_cost = cost_a + cost_b;
		stack_a = stack_a->next;
	}
}

void	total_cost(t_stack *a, t_stack *b)
{
	calculate_total_cost(a, b);
}
