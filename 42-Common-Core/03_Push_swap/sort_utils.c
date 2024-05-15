/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:46:53 by neleon            #+#    #+#             */
/*   Updated: 2024/05/15 16:28:35 by neleon           ###   ########.fr       */
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

void	sort_main(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = *a;
	stack_b = *b;
	if (ft_stack_size(stack_a) == 3)
	{
		sort_three_a(&stack_a);
	}
	else
	{
		sort_b(&stack_a, &stack_b);
		sort_three_a(&stack_a);
		sort_a(&stack_a, &stack_b);
		last_sort(&stack_a);
	}
}
