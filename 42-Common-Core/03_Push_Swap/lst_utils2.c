/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:50:00 by neleon            #+#    #+#             */
<<<<<<< HEAD:42-Common-Core/03_Push_swap/lst_utils2.c
/*   Updated: 2024/05/15 16:25:47 by neleon           ###   ########.fr       */
=======
/*   Updated: 2024/05/14 20:10:19 by neleon           ###   ########.fr       */
>>>>>>> 51801e933458986ca21060c0744716e02b579aa1:42-Common-Core/03_Push_Swap/lst_utils2.c
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

int	mid_stack(t_stack *lst)
{
	int	mid;

	mid = ft_stack_size(lst) / 2;
	return (mid);
}
