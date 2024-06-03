/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:51:39 by neleon            #+#    #+#             */
/*   Updated: 2024/04/16 11:00:12 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack *lst)
{
	int	i;
	int	mid;

	i = 0;
	mid = mid_stack(lst);
	if (!lst)
		return ;
	while (lst)
	{
		lst->index = i;
		if (i <= mid)
			lst->is_in_top = 1;
		else
			lst->is_in_top = 0;
		lst = lst->next;
		i++;
	}
}

void	target_a_in_b(t_stack *a, t_stack *b)
{
	t_stack	*stack_a;
	t_stack	*min_node;
	t_stack	*max_node;

	stack_a = a;
	min_node = find_min(b);
	max_node = find_max(b);
	while (stack_a)
	{
		if ((stack_a->nb < min_node->nb) || (stack_a->nb > max_node->nb))
			stack_a->target_node = max_node;
		else
			find_target(a, b);
		stack_a = stack_a->next;
	}
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*stack_b;
	t_stack	*target;
	int		nb;

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

void	moves_calcul(t_stack *lst)
{
	t_stack	*stack;
	int		stack_len;

	stack = lst;
	index_in_stack(stack);
	stack_len = ft_stack_size(stack);
	while (stack)
	{
		if (stack->is_in_top)
			stack->moves_to_top = stack->index;
		else
			stack->moves_to_top = stack_len - stack->index;
		stack = stack->next;
	}
}
