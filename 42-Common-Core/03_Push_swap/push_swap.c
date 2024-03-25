/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:04:45 by neleon            #+#    #+#             */
/*   Updated: 2024/03/25 23:36:12 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac > 1)
	{
		if (ac == 2)
		{
			// split
		}
		else if (ac > 2)
		{
			// while (i < ac)
			// {
			// 	if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i])))
			// 		print_error();
			// 	i++;
			// }
			init_stack(&a, av);
			ft_printf("Stack a : \n");
			print_stack(a);
			push_top_to_stack(&a, &b);
			ft_printf("\nStack b : \n");
			print_stack(b);
			push_top_to_stack(&a, &b);
			ft_printf("\n");
			print_stack(b);
			ft_printf("\nStack a : \n");
			print_stack(a);
			ft_printf("\nSwap a : \n");
			rrr(&a, &b);
			ft_printf("\nSwap a : \n");
			print_stack(a);
			ft_printf("\nSwap b : \n");
			print_stack(b);
		}
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;

	tmp = stack;
	while (tmp)
	{
		nbr = tmp->nb;
		ft_printf(" %d", nbr);
		tmp = tmp->next;
	}
}
