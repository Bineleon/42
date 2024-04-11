/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/11 17:58:22 by neleon           ###   ########.fr       */
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
			stack_a->target_node = min_node;
		stack_a = stack_a->next;
	}
}

t_stack	*find_target(t_stack *a, t_stack *b)
{
	t_stack	*target;
	int		nb;

	target = b;
	nb = INT_MIN;
	while(target)
	{
		
		target = target->next;
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