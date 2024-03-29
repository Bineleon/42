/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:04:45 by neleon            #+#    #+#             */
/*   Updated: 2024/03/29 15:27:21 by neleon           ###   ########.fr       */
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
		if (ac == 0)
		{
			// split
		}
		else if (ac >= 2)
		{
			init_stack(&a, av);
			while (i < ac)
			{
				if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
					|| is_not_int(ft_atoi(av[i])))
					print_error();
				i++;
			}
			// ft_printf("Stack a : \n");
			// print_stack(a);
			// push_top_to_stack(&a, &b);
			// ft_printf("\nStack b : \n");
			// print_stack(b);
			// push_top_to_stack(&a, &b);
			// ft_printf("\n");
			// print_stack(b);
			// ft_printf("\nStack a : \n");
			// print_stack(a);
			// ft_printf("\nSwap a : \n");
			// rrr(&a, &b);
			// ft_printf("\nSwap a : \n");
			// print_stack(a);
			// ft_printf("\nSwap b : \n");
			// print_stack(b);
			// ft_printf("\nMin a = %d\n", find_min(a));
			// ft_printf("Max a = %d\n", find_max(a));
			// print_stack(a);
			// ft_printf("\n");
			// sort_three_a(&a);
			// print_stack(a);

		}
	}
	return (0);
}

