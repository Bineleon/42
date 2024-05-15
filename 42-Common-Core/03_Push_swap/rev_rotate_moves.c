/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:50:45 by neleon            #+#    #+#             */
/*   Updated: 2024/05/15 16:27:38 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rev_rotate(t_stack **top)
{
	t_stack	*last;
	t_stack	*last2;

	if (!(*top) || !(*top)->next)
		return ;
	last = ft_stacklast(*top);
	last2 = before_last(*top);
	last2->next = NULL;
	last->next = *top;
	*top = last;
}

void	rev_rotate_a(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
