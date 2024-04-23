/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:01:45 by neleon            #+#    #+#             */
/*   Updated: 2024/04/23 18:27:10 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	get_cheapest(t_stack *a)
{
	// t_stack *stack_a;
	t_stack	*cheapest;

	cheapest = a;
	// stack_a = a;
	while (a)
	{
		if (a->moves_to_top < cheapest->moves_to_top)
			cheapest = a;
		a = a->next;
	}
	cheapest->is_cheapest = 1;
}

t_stack	*find_cheapest(t_stack *a)
{
	if (!a)
		return (NULL);
	while(!(a->is_cheapest))
		a = a->next;
	return (a);
}

void	moves_calcul(t_stack *a, t_stack *b)
{
	// t_stack	*stack_a;
	int		stack_len_a;
	int		stack_len_b;

	// stack_a = a;
	stack_len_a = ft_stack_size(a);	
	stack_len_b = ft_stack_size(b);
	index_in_stack(a);
	index_in_stack(b);
	while (a)
	{
		if (a->is_in_top)
			a->moves_to_top = a->index;
		else
			a->moves_to_top = stack_len_a - a->index;
		if (a->target_node->is_in_top)
            a->moves_to_top += a->target_node->index;
        else
            a->moves_to_top += stack_len_b - a->target_node->index;
		a = a->next;
	}
}