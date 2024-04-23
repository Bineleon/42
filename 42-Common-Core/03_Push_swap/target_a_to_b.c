/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:46:01 by neleon            #+#    #+#             */
/*   Updated: 2024/04/23 18:46:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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