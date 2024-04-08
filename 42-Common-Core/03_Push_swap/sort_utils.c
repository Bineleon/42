/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:46:53 by neleon            #+#    #+#             */
/*   Updated: 2024/04/05 14:07:00 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_three_a(t_stack **lst)
{
	t_stack	*max;

	max = find_max(*lst);
	if (!*lst || ft_stack_size(*lst) != 3)
		return ;
    if (*lst == max)
        rotate_a(lst);
    else if ((*lst)->next == max)
        rev_rotate_a(lst);
    if (!is_sorted(*lst))
        swap_a(lst);
}

	// if (last->nb == max->nb && !is_sorted(*lst))
	// 	swap_a(lst);
	// else if ((*lst)->nb == max->nb)
	// {
	// 	rotate_a(lst);
	// 	if (!is_sorted(*lst))
	// 		swap_a(lst);
	// }
	// else if ((*lst)->nb == min->nb && (*lst)->next->nb == max->nb)
	// {
	// 	swap_a(lst);
	// 	rotate_a(lst);
	// }
	// else if (last->nb == min->nb && (*lst)->next->nb == max->nb)
	// 	rev_rotate_a(lst);

// int is_rev_sort_three(t_stack *lst)
// {
// 	int		max;
// 	int		min;
// 	t_stack	*last;
// 	t_stack	*first;

// 	max = find_max(lst);
// 	min = find_min(lst);
// 	first = lst;
// 	last = ft_stacklast(lst);
// 	if (first->nb == max && last->nb == min)
// 		return (1);
// 	return (0);
// }

int	is_sorted(t_stack *lst)
{
	while (lst->next)
	{
        if (lst->nb > lst->next->nb)
    	    return (0);
        lst = lst->next;
    }
	return (1);
}
