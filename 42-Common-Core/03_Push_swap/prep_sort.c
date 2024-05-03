	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:08:51 by neleon            #+#    #+#             */
/*   Updated: 2024/04/24 20:06:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack **lst)
{
	int		i;
	int		mid;
	t_stack	*stack;

	i = 0;
	stack = *lst;
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

void	prep_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_b;
	// int		stack_len_a = ft_stack_size(*a);
	int		i;

	i = 0;
	// stack_len_a = ft_stack_size(*a);
	while (i++ < 2)
		push_a(a, b);
	min_b = find_min(*b);
	if ((*b)->nb == min_b->nb)
		swap_b(b);
	else if ((*b)->nb < (*b)->next->nb)
		swap_b(b);
	push_a(a, b);
	if ((*b)->nb < (*b)->next->nb)
		swap_b(b);
	if ((*b)->next->nb < (*b)->next->next->nb)
	{
		rev_rotate_b(b);
		swap_b(b);
	}
}

void	prep_stack_a(t_stack **a, t_stack **b)
{
	index_in_stack(a);
	index_in_stack(b);
	target_a_in_b(a, b);
	target_cost(a, b);
	total_cost(*a, *b);
	get_cheapest(a);
}

void	prep_stack_b(t_stack **b, t_stack **a)
{
	index_in_stack(a);
	// ft_printf("Index a DONE\n");

	index_in_stack(b);
	// ft_printf("Index b DONE\n");

	find_target_b_in_a(*b, *a);
	// ft_printf("target b in a DONE\n");

	target_cost(b, a);
	// ft_printf("target cost DONE\n");

	total_cost(*b, *a);
	// ft_printf("total cost DONE\n");

	get_cheapest(b);
	// ft_printf("get cheapest DONE\n");
}
