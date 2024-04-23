/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/23 18:27:06 by neleon           ###   ########.fr       */
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



void	a_and_target_to_top(t_stack *a, t_stack *b)
{
	t_stack	*cheapest_a;

	index_in_stack(a);
	cheapest_a = find_cheapest(a);
	if (cheapest_a->is_in_top && cheapest_a->target_node->is_in_top)
	{
		while (cheapest_a->index != 0 || cheapest_a->target_node->index != 0)
		{
			rr(&a, &b);
			index_in_stack(cheapest_a);
			index_in_stack(b);
		}
		while (cheapest_a->index != 0)
		{
			rotate_a(&a);
			index_in_stack(cheapest_a);
		}
		while (cheapest_a->target_node->index != 0)
		{
			rotate_b(&b);
			index_in_stack(b);
		}
	}
}



t_stack	*find_node(t_stack *lst, int nb)
{
	t_stack	*stack;

	stack = lst;
	while (stack->nb != nb)
		stack = stack->next;
	return (stack);
}

void	target_a_in_b(t_stack *a, t_stack *b)
{
	// t_stack	*stack_a;
	t_stack	*min_node;
	t_stack	*max_node;

	// stack_a = a;
	min_node = find_min(b);
	max_node = find_max(b);
	while (a)
	{
		if ((a->nb < min_node->nb) || (a->nb > max_node->nb))
			a->target_node = max_node;
		else
			find_target(a, b);
		a = a->next;
	}
}



void	find_target(t_stack *a, t_stack *b)
{
	// t_stack *stack_a;
	t_stack	*stack_b;
	t_stack	*target;
	int		nb;

	// stack_a = a;
	while (a)
	{
		nb = INT_MIN;
		stack_b = b;
		while (stack_b)
		{
			if (a->nb > stack_b->nb && stack_b->nb > nb)
			{
				target = stack_b;
				nb = stack_b->nb;
			}
			stack_b = stack_b->next;
		}
		a->target_node = target;
		a = a->next;
	}
}

// void	target_b_in_a(t_stack *a, t_stack *b)
// {
// 	t_stack *stack_b;
// 	t_stack *min_node;
// 	t_stack *max_node;

// 	stack_b = b;
// 	min_node = find_min(a);
// 	max_node = find_max(a);
// 	while (stack_b)
// 	{
// 		if (stack_b->nb > max_node->nb)
// 			stack_b->target_node = min_node;
// 		else
// 			stack_b->target_node = max_node;
// 		stack_b = stack_b->next;
// 	}
// }