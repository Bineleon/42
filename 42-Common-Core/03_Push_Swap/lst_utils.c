/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:33:12 by neleon            #+#    #+#             */
<<<<<<< HEAD:42-Common-Core/03_Push_swap/lst_utils.c
/*   Updated: 2024/05/15 16:25:36 by neleon           ###   ########.fr       */
=======
/*   Updated: 2024/05/14 20:09:53 by neleon           ###   ########.fr       */
>>>>>>> 51801e933458986ca21060c0744716e02b579aa1:42-Common-Core/03_Push_Swap/lst_utils.c
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*ft_stacknew(int nb)
{
	t_stack	*new;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!(*lst) && new)
		*lst = new;
	else if (*lst && new)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	else
		return (NULL);
	return (lst);
}

t_stack	*before_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
