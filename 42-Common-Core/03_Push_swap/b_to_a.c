/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:09:38 by neleon            #+#    #+#             */
/*   Updated: 2024/04/24 20:24:26 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


void	target_b_in_a(t_stack **b, t_stack **a)
{
	// t_stack	*stack_a;
	// t_stack	*min_node;
	t_stack	*max_node;

	max_node = find_max(*a);
	// stack_a = a;
	// min_node = find_min(b);
	while (*b)
	{	

		if ((*b)->nb > max_node->nb)
		{
			(*b)->target_node = max_node;
		}
		else
		{

			find_target_b_in_a(*b, *a);
		}
		(*b) = (*b)->next;
	}
}

void	find_target_b_in_a(t_stack *b, t_stack *a)
{
	t_stack	*stack_a;
	t_stack	*target;
	int		target_nb;
	t_stack	*min_node;
	
	ft_printf("find target START\n");
	min_node = find_min(a);
	while (b)
	{
		ft_printf("while b START\n");
		ft_printf("b->nb : %d\n", b->nb);

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
			b->target_node = min_node;
		else
			b->target_node = target;
		b = b->next;

	}
}

			// ft_printf("stack_a nb : %d\n", stack_a->nb);
			// if (b->nb > target_nb)
			// {
			// 	(b)->target_node = min_node;
			// 	ft_printf("target_node max %d\n", b->target_node->nb);

			// }