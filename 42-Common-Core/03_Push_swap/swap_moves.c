/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:49:58 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 20:32:41 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*top || !(*top)->next)
		return ;
	else if (!(*top)->next->next)
	{
		tmp = *top;
		tmp2 = (*top)->next;
		tmp->next = NULL;
		tmp2->next = tmp;
		*top = tmp2;
	}
	else
	{
		tmp = *top;
		tmp2 = (*top)->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		*top = tmp2;
	}
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
