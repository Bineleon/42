/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:33:58 by neleon            #+#    #+#             */
/*   Updated: 2024/03/25 18:54:40 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_top_to_stack(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!src)
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
