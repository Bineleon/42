/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 17:21:18 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		prep_stack_b(b, a);
		cheapest = find_cheapest(*b);
		b_and_target_to_top(b, cheapest, a);
		push_a(b, a);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		size;
	int		seg;

	seg = -1;
	size = ft_stack_size(*a);
	prep_stack_a(a);
	while (++seg <= 5)
	{
		current = *a;
		while (current && size > 3)
		{
			assign_cost_in_a(a);
			get_cheapest_by_segment(a, seg);
			if (current->segment == seg && current->is_cheapest)
			{
				node_to_top(a, current);
				push_b(a, b);
				current = *a;
				size--;
			}
			else
				current = current->next;
		}
	}
}

void	last_sort(t_stack **a)
{
	while ((*a)->nb != find_min(*a)->nb)
	{
		index_in_stack(a);
		if (find_min(*a)->is_in_top)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		sort_b(a, b);
		sort_three_a(a);
		sort_a(a, b);
		last_sort(a);
	}
}
