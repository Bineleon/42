/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:25:18 by neleon            #+#    #+#             */
<<<<<<< HEAD:42-Common-Core/03_Push_swap/sort_utils2.c
/*   Updated: 2024/05/15 16:28:45 by neleon           ###   ########.fr       */
=======
/*   Updated: 2024/05/14 20:19:53 by neleon           ###   ########.fr       */
>>>>>>> 51801e933458986ca21060c0744716e02b579aa1:42-Common-Core/03_Push_Swap/sort_utils2.c
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*find_max(t_stack *lst)
{
	t_stack	*max_node;
	int		max;

	max_node = lst;
	max = INT_MIN;
	while (lst)
	{
		if (lst->nb > max)
		{
			max_node = lst;
			max = lst->nb;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *lst)
{
	t_stack	*min_node;
	int		min;

	min_node = lst;
	min = INT_MAX;
	while (lst)
	{
		if (lst->nb < min)
		{
			min_node = lst;
			min = lst->nb;
		}
		lst = lst->next;
	}
	return (min_node);
}
