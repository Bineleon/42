/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:46:53 by neleon            #+#    #+#             */
/*   Updated: 2024/03/28 20:31:12 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_three_a(t_stack **lst)
{
	int		max;
	int		min;
	
	max = find_max(*lst);
	min = find_min(*lst);
	if (!*lst || ft_stack_size(*lst) != 3)
		return ;
	if (is_sorted_three(*lst))
		return;
	if (is_rev_sort_three(*lst))
		rotate_a(lst);
	else if ((*lst)->next->nb == max)
		rev_rotate_a(lst);
	if (!is_sorted_three(*lst))
		swap_a(lst);
}

int is_rev_sort_three(t_stack *lst)
{
	int		max;
	int		min;
	t_stack	*last;
	t_stack	*first;

	max = find_max(lst);
	min = find_min(lst);
	first = lst;
	last = ft_stacklast(lst);
	if (first-> nb == max && last->nb == min)
		return (1);
	return (0);
}

int is_sorted_three(t_stack *lst)
{
	int		max;
	int		min;
	t_stack	*last;
	t_stack	*first;

	max = find_max(lst);
	min = find_min(lst);
	first = lst;
	last = ft_stacklast(lst);
	if (first-> nb == min && last->nb == max)
		return (1);
	return (0);
}
