/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:08:51 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 18:44:22 by neleon           ###   ########.fr       */
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
	int		i;

	// int		stack_len_a = ft_stack_size(*a);
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

void	prep_stack_a(t_stack **a)
{
	int	*pivots;
	int	size;

	size = ft_stack_size(*a);
	pivots = malloc(4 * sizeof(int));
    if (!pivots)
	{
        return;
	}
	pivots = find_pivots(*a, size, pivots);
	assign_segment(a, pivots);
}

void	prep_stack_b(t_stack **b, t_stack **a)
{
	// t_stack *tmp = *b;
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
	set_cheapest_to_null(b);
	get_cheapest(b);
	// while (tmp)
	// {
	// 	ft_printf("nb : %d cheapest? : %d\n", tmp->nb, tmp->is_cheapest);
	// 	tmp = tmp->next;
	// }
	// ft_printf("get cheapest DONE\n");
}
