/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:01:45 by neleon            #+#    #+#             */
/*   Updated: 2024/04/25 17:56:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	get_cheapest(t_stack *a)
{
	t_stack *stack_a;
	t_stack	*cheapest;
	int cheapest_cost;

	cheapest = NULL;
	cheapest_cost = INT_MAX;
	stack_a = a;
	while (stack_a)
	{
		if (stack_a->total_cost < cheapest_cost)
		{
			cheapest_cost = stack_a->total_cost;
			cheapest = stack_a;
		}	
		stack_a = stack_a->next;
	}
	cheapest->is_cheapest = 1;
}

t_stack	*find_cheapest(t_stack *a)
{
	get_cheapest(a);
	if (!a)
		return (NULL);
	while(!(a->is_cheapest))
		a = a->next;
	return (a);
}

void	target_cost(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	int		stack_len;

	stack_a = *a;
	// index_in_stack(stack_a);
	stack_len = ft_stack_size(*b);
	// index_in_stack(b);
	while (stack_a)
	{
		if (stack_a->target_node->is_in_top)
			stack_a->target_cost = stack_a->target_node->index;
		else
			stack_a->target_cost = stack_len - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

// void	total_cost(t_stack *a, t_stack *b)
// {
// 	// t_stack	*stack_a;
// 	int		stack_len_a;
// 	int		stack_len_b;

// 	// stack_a = a;
// 	stack_len_a = ft_stack_size(a);	
// 	stack_len_b = ft_stack_size(b);
// 	index_in_stack(a);
// 	index_in_stack(b);
// 	while (a)
// 	{
// 		// if (a->is_in_top)
// 		// 	a->total_cost = a->index;
// 		// else
// 		// 	a->total_cost = stack_len_a - a->index;
// 		if ((a->is_in_top && a->target_node->is_in_top)
// 			|| !(a->is_in_top && a->target_node->is_in_top))
// 		{
// 			if ((a->total_cost - a->target_cost) > a->target_cost)
// 				a->total_cost = a->total_cost - a->target_cost;
// 			else if ((a->total_cost - a->target_cost) < a->target_cost)
// 				a->total_cost = a->total_cost - (a->total_cost - a->target_cost);
// 			else if ((a->total_cost - a->target_cost) == a->total_cost)
// 				a->total_cost = a->target_cost;
// 		}	
// 		else if (a->is_in_top && !a->target_node->is_in_top) 
//             	a->total_cost = a->index + (stack_len_b - a->target_node->index);	
// 		else if (!a->is_in_top && a->target_node->is_in_top)
//             	a->total_cost = (stack_len_a - a->index) + a->target_node->index;
// 		a = a->next;
// 	}
// }


void	total_cost(t_stack *a, t_stack *b)
{
	// t_stack	*stack_a;
	int		stack_len_a;
	int		stack_len_b;

	// stack_a = a;
	stack_len_a = ft_stack_size(a);	
	stack_len_b = ft_stack_size(b);
	// index_in_stack(a);
	// target_cost(a, b);
	while (a)
	{
		if (a->is_in_top)
			a->total_cost = a->index;
		else
			a->total_cost = stack_len_a - a->index;
		if ((a->is_in_top && a->target_node->is_in_top)
			|| !(a->is_in_top && a->target_node->is_in_top))
		{
			if ((a->total_cost - a->target_cost) > a->target_cost)
				a->total_cost = a->total_cost - a->target_cost;
			else if ((a->total_cost - a->target_cost) < a->target_cost)
				a->total_cost = a->total_cost - (a->total_cost - a->target_cost);
			else if ((a->total_cost - a->target_cost) == a->total_cost)
			{
				printf("\n\nhereee = %d\n\n\n", a->target_cost);
				a->total_cost = a->target_cost;
				// a = a->next;
				//continue ;
			}
		}	
		if (a->target_node->is_in_top)
            a->total_cost += a->target_node->index;
        else
            a->total_cost += stack_len_b - a->target_node->index;
		a = a->next;
	}
}