/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:46:01 by neleon            #+#    #+#             */
/*   Updated: 2024/05/03 17:39:12 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// void	target_a_in_b(t_stack **a, t_stack **b)
// {
// 	t_stack	*stack_a;
// 	t_stack	*min_node;
// 	t_stack	*max_node;

// 	stack_a = *a;
// 	min_node = find_min(*b);
// 	max_node = find_max(*b);
// 	while (stack_a)
// 	{
// 		if ((stack_a->nb < min_node->nb) || (stack_a->nb > max_node->nb))
// 			stack_a->target_node = max_node;
// 		else
// 			find_target(a, b);
// 		stack_a = stack_a->next;
// 	}
// }

void	target_a_in_b(t_stack **a, t_stack **b)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	t_stack	*target;
	int		nb;

	t_stack	*min_node;
	t_stack	*max_node;

	min_node = find_min(*b);
	max_node = find_max(*b);
	stack_a = *a;
	index_in_stack(a);
	index_in_stack(b);
	// target = NULL;
	while (stack_a)
	{
		nb = INT_MIN;
		stack_b = *b;
		if ((stack_a->nb < min_node->nb) || (stack_a->nb > max_node->nb))
			stack_a->target_node = max_node;
		else
		{
			while (stack_b)
			{
				if (stack_a->nb > stack_b->nb && stack_b->nb > nb)
				{
					target = stack_b;
					nb = stack_b->nb;
				}
				stack_b = stack_b->next;
			}
			stack_a->target_node = target;
		}
		stack_a = stack_a->next;
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
			// i = 0;
			while(i < cheapest->total_cost)
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
			// i = 0;
			while(i < cheapest->total_cost)
			{
				rotate_a(a);
				i++;
			}
		}
	}
	else if (!cheapest->is_in_top && !cheapest->target_node->is_in_top)
	{
		if (cost_a < cheapest->target_cost)
		{
			while(i < cost_a)
			{
				rrr(a, b);
				i++;
			}
			// i = 0;
			while(i < cheapest->total_cost)
			{
				rev_rotate_b(b);
				i++;
			}
		}
		else if (cost_a == cheapest->target_cost)
		{
			while(i < cost_a)
			{
				rrr(a, b);
				i++;
			}
		}
		else
		{
			while(i < cheapest->target_cost)
			{
				rrr(a, b);
				i++;
			}
			// i = 0;
			while(i < cheapest->total_cost)
			{
				rev_rotate_a(a);
				i++;
			}
		}
	}
	else if (!cheapest->is_in_top && cheapest->target_node->is_in_top)
	{
		while(i < cheapest->target_cost)
		{
			rotate_b(b);
			i++;
		}
		i = 0;
		while (i < cost_a)
		{
			rev_rotate_a(a);
			i++;
		}
	}
	else if (cheapest->is_in_top && !cheapest->target_node->is_in_top)
	{
		while(i < cheapest->target_cost)
		{
			rev_rotate_b(b);
			i++;
		}
		i = 0;
		while (i < cost_a)
		{
			rotate_a(a);
			i++;
		}
	}

}
