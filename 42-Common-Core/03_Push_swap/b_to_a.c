/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:09:38 by neleon            #+#    #+#             */
/*   Updated: 2024/05/03 17:27:57 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


// void	target_b_in_a(t_stack **b, t_stack **a)
// {
// 	t_stack	*stack_b;
// 	// t_stack	*min_node;
// 	t_stack	*max_node;

// 	max_node = find_max(*a);
// 	stack_b = *b;
// 	// min_node = find_min(b);
// 	while (stack_b)
// 	{

// 		if ((stack_b)->nb > max_node->nb)
// 		    (stack_b)->target_node = max_node;
// 		else
// 			find_target_b_in_a(stack_b, *a);
// 		(stack_b) = (stack_b)->next;
// 	}
// }

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

// int	calculate_initial_cost(t_stack *node, int stack_length)
// {
// 	if (node->is_in_top)
// 		return (node->index);
// 	else
// 		return (stack_length - node->index);
// }

void	b_and_target_to_top(t_stack **b, t_stack *cheapest, t_stack **a)
{
	int cost_b;
	int i;

	i = 0;
	cost_b = cheapest->total_cost - cheapest->target_cost;
	if (cheapest->is_in_top && cheapest->target_node->is_in_top)
	{
		if (cost_b < cheapest->target_cost)
		{
			while(i < cost_b)
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
		else if (cost_b == cheapest->target_cost)
		{
			while(i < cost_b)
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
				rotate_b(b);
				i++;
			}
		}
	}
	else if (!cheapest->is_in_top && !cheapest->target_node->is_in_top)
	{
		if (cost_b < cheapest->target_cost)
		{
			while(i < cost_b)
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
		else if (cost_b == cheapest->target_cost)
		{
			while(i < cost_b)
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
			i = 0;
			while(i < cheapest->total_cost)
			{
				rev_rotate_b(b);
				i++;
			}
		}
	}
	else if (!cheapest->is_in_top && cheapest->target_node->is_in_top)
	{
		while(i < cheapest->target_cost)
		{
			rotate_a(a);
			i++;
		}
		i = 0;
		while (i < cost_b)
		{
			rev_rotate_b(b);
			i++;
		}
	}
	else if (cheapest->is_in_top && !cheapest->target_node->is_in_top)
	{
		while(i < cheapest->target_cost)
		{
			rev_rotate_a(a);
			i++;
		}
		i = 0;
		while (i < cost_b)
		{
			rotate_b(b);
			i++;
		}
	}
}


			// ft_printf("stack_a nb : %d\n", stack_a->nb);
			// if (b->nb > target_nb)
			// {
			// 	(b)->target_node = min_node;
			// 	ft_printf("target_node max %d\n", b->target_node->nb);

			// }
