/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:03:42 by neleon            #+#    #+#             */
<<<<<<< HEAD:42-Common-Core/03_Push_swap/stack_utils.c
/*   Updated: 2024/05/15 16:29:08 by neleon           ###   ########.fr       */
=======
/*   Updated: 2024/05/14 20:31:43 by neleon           ###   ########.fr       */
>>>>>>> 51801e933458986ca21060c0744716e02b579aa1:42-Common-Core/03_Push_Swap/stack_utils.c
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

	i = 1;
	*stack_a = ft_stacknew(ft_atoi(av[0]));
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
