/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:46:53 by neleon            #+#    #+#             */
/*   Updated: 2024/03/26 00:19:32 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void sort_three(t_stack *lst)
{
	int max;
	
	if (!lst || ft_stack_size(lst) != 3)
		return;
	max = lst->nb;
}