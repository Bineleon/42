/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:03:42 by neleon            #+#    #+#             */
/*   Updated: 2024/03/29 15:24:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stack(t_stack **stack_a, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	*stack_a = ft_stacknew(ft_atoi(av[1]));
	while (av[i])
	{
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;
	int first_seen;

	first_seen = 1;
	tmp = stack;
	while (tmp)
	{
		nbr = tmp->nb;
		if (first_seen == 1)
		{
			ft_printf("%d", nbr);
			first_seen = 0;
		}
		else if (first_seen == 0)
			ft_printf(" %d", nbr);
		tmp = tmp->next;
	}
}
