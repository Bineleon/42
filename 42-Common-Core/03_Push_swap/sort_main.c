/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:57:14 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 21:30:45 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	int		count;

	a = NULL;
	b = NULL;
	split_args = NULL;
	i = 1;
	count = ft_count_words(av[1], ' ');
	split_args = ft_split(av[1], ' ');
	if (ac > 1)
	{
		if (ac == 2 && av[1][0])
		{
			while (i < count)
			{
				if (not_digit(split_args[i]) || is_duplicate(a,
						ft_atoi(split_args[i]))
					|| is_not_int(ft_atoi(split_args[i])))
					print_error();
				i++;
			}
			init_split(&a, split_args);
		}
		if (ac > 2)
		{
			init_stack(&a, av);
			while (i < ac)
			{
				if (not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
					|| is_not_int(ft_atoi(av[i])))
					print_error();
				i++;
			}
		}
		// sort_main(&a, &b);
		// t_stack *lst = a;
		if (ft_stack_size(a) == 3)
		{
			sort_three_a(&a);
			print_stack(a);
		}
		else
		{
			sort_b(&a, &b);
			sort_three_a(&a);
			sort_a(&a, &b);
			last_sort(&a);
		}
		print_stack(a);
	}
}
