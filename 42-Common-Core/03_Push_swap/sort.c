/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/05/15 17:51:51 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted_b(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		prep_stack_b(b, a);
		cheapest = find_cheapest(*b);
		b_and_target_to_top(b, cheapest, a);
		push_b(b, a);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		seg;

	prep_stack_a(a);
	size = ft_stack_size(*a);
	seg = 0;
	while (seg++ <= 5)
	{
		current = *a;
		while (current && size > 3)
		{
			assign_cost_in_a(a);
			get_cheapest_by_segment(a, seg);
			if (current->segment == seg && current->is_cheapest)
			{
				node_to_top(a, current);
				push_a(a, b);
				current = *a;
				size--;
			}
			else
				current = current->next;
		}
	}
	free_stack(&current);
}

void	last_sort(t_stack **a)
{
	index_in_stack(a);
	while ((*a)->nb != find_min(*a)->nb)
	{
		if (find_min(*a)->is_in_top)
			rotate_a(a);
		else
			rev_rotate_a(a);
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
