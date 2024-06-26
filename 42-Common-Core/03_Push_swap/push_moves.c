/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:33:58 by neleon            #+#    #+#             */
/*   Updated: 2024/05/29 00:41:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_top_to_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	push_top_to_stack(a, b);
	ft_printf("pb\n");
}

void	push_a(t_stack **b, t_stack **a)
{
	push_top_to_stack(b, a);
	ft_printf("pa\n");
}
