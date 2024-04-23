/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/23 22:12:54 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack *lst)
{
	int	i;
	int	mid;
	t_stack *stack;

	i = 0;
	stack = lst;
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

void	a_and_target_to_top(t_stack **a, t_stack *cheapest, t_stack **b)
{
	int cost_a;
	int i;

	i = 0;
	cost_a = cheapest->total_cost - cheapest->target_cost;
	if (cheapest->is_in_top && cheapest->target_node->is_in_top)
	{
		if (cost_a < cheapest->target_cost)
		{
			while(i < cost_a)
			{
				rr(a, b);
				i++;
			}
			i = 0;
			while(i < cheapest->target_cost)
			{
				rotate_b(b);
				i++;
			}
		}
		else if (cost_a == cheapest->target_cost)
		{
			while(i < cost_a)
			{
				rr(a, b);
				i++;
			}
		}
		else
		{
			while(i < cheapest->target_cost)
			{
				rr(a, b);
				i++;
			}
			i = 0;
			while(i < cost_a)
			{
				rotate_a(a);
				i++;
			}
		}
	}
}

// void	a_and_target_to_top(t_stack *a, t_stack *b)
// {
// 	t_stack	*cheapest_a;

// 	index_in_stack(a);
// 	cheapest_a = find_cheapest(a);
// 	if (cheapest_a->is_in_top && cheapest_a->target_node->is_in_top)
// 	{
// 		while (cheapest_a->index != 0 || cheapest_a->target_node->index != 0)
// 		{
// 			rr(&a, &b);
// 			index_in_stack(cheapest_a);
// 			index_in_stack(b);
// 		}
// 		while (cheapest_a->index != 0)
// 		{
// 			rotate_a(&a);
// 			index_in_stack(cheapest_a);
// 		}
// 		while (cheapest_a->target_node->index != 0)
// 		{
// 			rotate_b(&b);
// 			index_in_stack(b);
// 		}
// 	}
// }

t_stack	*find_node(t_stack *lst, int nb)
{
	t_stack	*stack;

	stack = lst;
	while (stack->nb != nb)
		stack = stack->next;
	return (stack);
}

