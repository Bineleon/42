/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:46:01 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 20:37:07 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	assign_target(t_stack *a, t_stack **b, t_stack **target, int nb)
{
	t_stack	*stack_b;

	stack_b = *b;
	while (stack_b)
	{
		if (a->nb > stack_b->nb && stack_b->nb > nb)
		{
			target = &stack_b;
			nb = stack_b->nb;
		}
		stack_b = stack_b->next;
	}
}

void	target_a_in_b(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*target;
	int		nb;

	stack_a = *a;
	index_in_stack(a);
	index_in_stack(b);
	while (stack_a)
	{
		nb = INT_MIN;
		stack_b = *b;
		if ((stack_a->nb < find_min(*b)->nb)
			|| (stack_a->nb > find_max(*b)->nb))
			stack_a->target_node = find_max(*b);
		else
			assign_target(*a, b, &target, nb);
		stack_a = stack_a->next;
	}
}

void	double_rotate(t_stack **a, t_stack **b, int count,
		void (*move)(t_stack **, t_stack **))
{
	int	i;

	i = 0;
	while (i < count)
	{
		move(a, b);
		i++;
	}
}

void	single_rotate(t_stack **stack, int count, void (*move)(t_stack **))
{
	int	i;

	i = 0;
	while (i < count)
	{
		move(stack);
		i++;
	}
}

void	node_to_top(t_stack **a, t_stack *node)
{
	int	cost_a;
	int	stack_len;

	stack_len = ft_stack_size(*a);
	cost_a = calculate_node_cost(node, stack_len);
	if (node->is_in_top)
		single_rotate(a, cost_a, rotate_a);
	else
		single_rotate(a, cost_a, rev_rotate_a);
}
