/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:46:53 by neleon            #+#    #+#             */
/*   Updated: 2024/04/01 18:59:10 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_three_a(t_stack **lst)
{
	t_stack	*max;
	t_stack	*min;
	t_stack	*last;

	last = ft_stacklast(*lst);
	max = find_max(*lst);
	min = find_min(*lst);
	if (!*lst || ft_stack_size(*lst) != 3)
		return ;
	if (is_sorted_three(*lst))
		return ;
	if (last->nb == max->nb && !is_sorted_three(*lst))
	{
		swap_a(lst);
		ft_printf("swap : ");
		printf("-------------------\n");
		printf("apres swap %d\n", (*lst)->nb);
		print_stack(*lst);
	}
	else if ((*lst)->nb == max->nb)
	{
		rotate_a(lst);
		ft_printf("rotate : ");
		print_stack(*lst);
		if (!is_sorted_three(*lst))
		{
			swap_a(lst);
			ft_printf("swap : ");
			print_stack(*lst);
		}
	}
	else if ((*lst)->nb == min->nb && (*lst)->next->nb == max->nb)
	{
		swap_a(lst);
		ft_printf("swap : ");
		print_stack(*lst);
		rotate_a(lst);
		ft_printf("rotate : ");
		print_stack(*lst);
	}
	else if (last->nb == min->nb && (*lst)->next->nb == max->nb)
	{
		rev_rotate_a(lst);
		ft_printf("rev_rotate : ");
		print_stack(*lst);
	}
}

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

int	is_sorted_three(t_stack *lst)
{
	t_stack	*max;
	t_stack	*min;
	t_stack	*last;
	t_stack	*first;

	max = find_max(lst);
	min = find_min(lst);
	first = lst;
	last = ft_stacklast(lst);
	if (first->nb == min->nb && last->nb == max->nb)
		return (1);
	return (0);
}
