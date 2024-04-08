/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/08 09:49:20 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack **lst)
{
	int	i;
	int	mid;

	i = 0;
	mid = mid_stack(*lst);
	if (!*lst)
		return;
	while (*lst)
	{
		(*lst)->index = i;
		if (i <= mid)
			(*lst)->is_in_top = 1;
		else
			(*lst)->is_in_top = 0;
        printf("Index : %d\n", (*lst)->index);
		*lst = (*lst)->next;
		i++;
	}
}
