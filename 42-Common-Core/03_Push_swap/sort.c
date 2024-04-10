/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/10 15:31:14 by neleon           ###   ########.fr       */
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
	t_stack *stack;

	stack = lst;
	while (stack->nb != nb)
		stack = stack->next;
	return (stack);
}