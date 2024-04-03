/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:04:45 by neleon            #+#    #+#             */
/*   Updated: 2024/04/02 15:40:42 by neleon           ###   ########.fr       */
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
	int j = 0;
	int count = ft_count_words(av[1], ' ');
	if (ac > 1)
	{
		if (ac == 2 && av[1][0])
		{
			split_args = ft_split(av[1], ' ');
			while (j < count)
			{
				printf("split : %s\n", split_args[j]);
				j++;
			}
			while (i < count)
			{
				if(not_digit(split_args[i]) || is_duplicate(a, ft_atoi(split_args[i]))
					|| is_not_int(ft_atoi(split_args[i])))
					print_error();
				i++;
			}
			init_split(&a, split_args);
		}
		if (ac >= 2)
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
		// swap_a(&a);
		// ft_printf("\nSwap a : \n");
		// print_stack(a);
		// ft_printf("\nSwap b : \n");
		// swap_b(&b);
		// print_stack(b);
		t_stack *min = find_min(a);
		t_stack *max = find_max(a);
		ft_printf("\nMin a = %d\n", min->nb);
		ft_printf("Max a = %d\n", max->nb);
		ft_printf("stack a : ");
		print_stack(a);
		sort_three_a(&a);
		print_stack(a);
		printf("coucou nb :%d\n", a->next->nb);
	}
	return (0);
}


// int	main(int ac, char **av)
// {
// 	int		i;
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	if (ac > 1)
// 	{
// 		if (ac == 0)
// 		{
// 			// split
// 		}
// 		else if (ac >= 2)
// 		{
// 			init_stack(&a, av);
// 			while (i < ac)
// 			{
// 				if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
// 					|| is_not_int(ft_atoi(av[i])))
// 					print_error();
// 				i++;
// 			}
// 			ft_printf("Stack a : \n");
// 			print_stack(a);
// 			push_top_to_stack(&a, &b);
// 			push_top_to_stack(&a, &b);
// 			push_top_to_stack(&a, &b);
// 			ft_printf("\n");
// 			print_stack(b);
// 			ft_printf("\nMin b = %d\n", find_min(b));
// 			ft_printf("Max b = %d\n", find_max(b));
// 			print_stack(a);
// 		}
// 	}
// 	return (0);
// }


// ft_printf("Stack a : \n");
// 			print_stack(a);
// 			push_top_to_stack(&a, &b);
// 			ft_printf("\nStack b : \n");
// 			print_stack(b);
// 			push_top_to_stack(&a, &b);
// 			ft_printf("\n");
// 			print_stack(b);
// 			ft_printf("\nStack a : \n");
// 			print_stack(a);
// 			ft_printf("\nSwap a : \n");
// 			rrr(&a, &b);
// 			ft_printf("\nSwap a : \n");
// 			print_stack(a);
// 			ft_printf("\nSwap b : \n");
// 			print_stack(b);
// 			ft_printf("\nMin a = %d\n", find_min(a));
// 			ft_printf("Max a = %d\n", find_max(a));
// 			print_stack(a);
// 			ft_printf("\n");
// 			sort_three_a(&a);
// 			print_stack(a);

