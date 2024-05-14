/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:57:14 by neleon            #+#    #+#             */
/*   Updated: 2024/05/13 18:48:05 by neleon           ###   ########.fr       */
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
			// while (i < ac)
			// {
			// 	if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
			// 		|| is_not_int(ft_atoi(av[i])))
			// 		print_error();
			// 	i++;
			// }
		}

		// prep sort b

		t_stack *lst = a;
		// ft_printf("Stack a : \n");
		// print_stack(lst);
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
		// ft_printf("\nStack a : \n");
		// print_stack(lst);
		// ft_printf("\nStack b : \n");
		// print_stack(b);

		// sort three a

		sort_three_a(&lst);
		// ft_printf("\nStack a sort_three: \n");
		// print_stack(lst);
		// prep_stack_b(&b, &lst);
		// prep sort b

		// t_stack *stack_b = b;
        // print_stack(lst);

        sort_a(&lst, &b);
        // ft_printf("\nStack a : \n");
		// print_stack(lst);
		// ft_printf("\nStack b : \n");
		// print_stack(b);
		// b_and_target_to_top(&b, b, &lst);
		// ft_printf("Stack a post top: \n");
		// print_stack(lst);
		// ft_printf("\nStack b post top: \n");
		// print_stack(b);
		// push_b(&b, &lst);
		// ft_printf("\nStack a : \n");
		// print_stack(lst);
		// ft_printf("\nStack b : \n");
		// print_stack(b);
		last_sort(&lst);
		ft_printf("\nStack a : \n");
		print_stack(lst);
		// while (stack_b)
		// {
		// 	ft_printf("\n");
		// 	ft_printf("Stack b : \n");
		// 	print_stack(b);
		// 	ft_printf("\nStack a : \n");
		// 	print_stack(lst);
		// 	printf("for nb = %d\n", stack_b->nb);
		// 	printf("	target = %d\n", stack_b->target_node->nb);
		// 	printf("	index : %d\n", stack_b->index);
		// 	printf("	cost : %d\n", stack_b->total_cost);
		// 	printf("	is_in_top : %d\n", stack_b->is_in_top);
		// 	printf("	target cost : %d\n", stack_b->target_cost);
		// 	printf("	target is_in_top : %d\n", stack_b->target_node->is_in_top);

		// 	printf("	cheapest : %d\n", stack_b->is_cheapest);

		// 	stack_b = stack_b->next;
		// }

	}
}
