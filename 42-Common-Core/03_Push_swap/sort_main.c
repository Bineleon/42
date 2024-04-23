/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:57:14 by neleon            #+#    #+#             */
/*   Updated: 2024/04/24 00:22:34 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char **split_args;

	a = NULL;
	b = NULL;
	split_args = NULL;
	i = 1;
	// int j = 0;
	int count = ft_count_words(av[1], ' ');
	split_args = ft_split(av[1], ' ');
	if (ac > 1)
	{
		if (ac == 2 && av[1][0])
		{
			while (i < count)
			{
				if(not_digit(split_args[i]) || is_duplicate(a, ft_atoi(split_args[i]))
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
				if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
					|| is_not_int(ft_atoi(av[i])))
					print_error();
				i++;
			}
		}
		t_stack *lst = a;
		ft_printf("Stack a : \n");
		print_stack(lst);
		// t_stack *min = find_min(a);
		// t_stack *max = find_max(a);
		// printf("min a = %d\n", min->nb);
		// printf("max a = %d\n", max->nb);
		// prep_sort(&lst, &b);
		// t_stack *lst2 = lst;
		// while (lst2)
		// {
		// 	ft_printf("\n");
		// 	ft_printf("Stack a : \n");
		// 	print_stack(lst2);
		// 	ft_printf("\nStack b : \n");
		// 	print_stack(b);
		// 	printf("for nb = %d\n", lst->nb);
		// 	printf("	target = %d\n", lst->target_node->nb);
		// 	printf("	index : %d\n", lst->index);
		// 	printf("	cost : %d\n", lst->total_cost);
		// 	printf("	target cost : %d\n", lst->target_cost);

		// 	printf("	cheapest : %d\n", lst->is_cheapest);

		// 	lst2 = lst2->next;
		// }
		sort_b(&lst, &b);
		ft_printf("\nStack a : \n");
		print_stack(lst);
		ft_printf("\nStack b : \n");
		print_stack(b);
		
	}
}