/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:03:42 by neleon            #+#    #+#             */
/*   Updated: 2024/03/24 21:42:23 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, char **av)
{
	int	i;
	int	j;
	
	j = 0;
	i = 2;
	*stack_a = ft_new(ft_atoi(av[1]));
	while (av[i])
	{
		ft_add_back(stack_a, ft_new(ft_atoi(av[i])));
		i++;
	}
	t_stack *temp = *stack_a;
	while (temp)
	{
		int nbr = temp->nb;
		ft_printf("%d ", nbr);
		temp = temp->next;
	}
}

// t_stack	*ft_new(void *content)
// {
// 	t_stack *new;

// 	new = malloc(1 * sizeof(t_stack));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }