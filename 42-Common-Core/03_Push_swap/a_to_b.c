/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:46:01 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 17:09:57 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
