/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:03:42 by neleon            #+#    #+#             */
/*   Updated: 2024/05/23 12:41:03 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stack(t_stack **stack_a, char **av)
{
	int	i;

	i = 2;
	*stack_a = ft_stacknew(ft_atoi(av[1]));
	while (av[i])
	{
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
}

void	init_split(t_stack **stack_a, char **av)
{
	int	i;
	char **split_args;

	i = 1;
	split_args = av;
	*stack_a = ft_stacknew(ft_atoi(split_args[0]));
	while (split_args[i])
	{
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(split_args[i])));
		i++;
	}
	while(*split_args)
	{
		free(*split_args);
		split_args++;
	}
	free(*split_args);
	
}

t_stack	*init_b(void)
{	
	return (NULL);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;
	int		first_seen;

	if (!stack)
		return ;
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
	ft_printf("\n");
}
