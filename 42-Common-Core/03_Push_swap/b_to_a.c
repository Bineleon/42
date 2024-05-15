/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:09:38 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 20:04:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	find_target_b_in_a(t_stack *b, t_stack *a)
{
	t_stack	*stack_a;
	t_stack	*target;
	int		target_nb;

	while (b)
	{
		target = NULL;
		target_nb = INT_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->nb > b->nb && stack_a->nb < target_nb)
			{
				target_nb = stack_a->nb;
				target = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (target_nb == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	both_to_top(t_stack **b, t_stack *cheapest, t_stack **a, int cost_b)
{
	int	target_cost;

	target_cost = calculate_node_cost(cheapest->target_node, ft_stack_size(*a));
	if (cheapest->is_in_top)
		double_rotate(a, b, ft_min(cost_b, target_cost), rr);
	else
		double_rotate(a, b, ft_min(cost_b, target_cost), rrr);
	if (cost_b < target_cost)
	{
		if (cheapest->is_in_top)
			single_rotate(a, target_cost - cost_b, rotate_a);
		else
			single_rotate(a, target_cost - cost_b, rev_rotate_a);
	}
	else if (cost_b > target_cost)
	{
		if (cheapest->is_in_top)
			single_rotate(b, cost_b - target_cost, rotate_b);
		else
			single_rotate(b, cost_b - target_cost, rev_rotate_b);
	}
}

void	b_and_target_to_top(t_stack **b, t_stack *cheapest, t_stack **a)
{
	int	cost_b;
	int	target_cost;

	target_cost = calculate_node_cost(cheapest->target_node, ft_stack_size(*a));
	cost_b = calculate_node_cost(cheapest, ft_stack_size(*b));
	if ((cheapest->is_in_top && cheapest->target_node->is_in_top)
		|| (!cheapest->is_in_top && !cheapest->target_node->is_in_top))
		both_to_top(b, cheapest, a, cost_b);
	else
	{
		if (cheapest->is_in_top)
		{
			single_rotate(a, target_cost, rev_rotate_a);
			single_rotate(b, cost_b, rotate_b);
		}
		else
		{
			single_rotate(a, target_cost, rotate_a);
			single_rotate(b, cost_b, rev_rotate_b);
		}
	}
}
