/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:50:00 by neleon            #+#    #+#             */
/*   Updated: 2024/04/08 17:34:02 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int	node;

	node = 0;
	while (lst)
	{
		lst = lst->next;
		node++;
	}
	return (node);
}

int mid_stack(t_stack *lst)
{
    int mid;

    mid = ft_stack_size(lst) / 2;
    return (mid);
}


int is_first(t_stack *lst, int nb)
{
	t_stack *stack;

	stack = lst;
	if (lst->nb == nb)
		return (1);
	return (0);
}