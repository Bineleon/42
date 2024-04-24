/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/24 17:10:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_sorted_b(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_b(t_stack **a, t_stack **b)
{
	// int		is_sorted;
	int		stack_len_a;
	t_stack	*cheapest;

	// is_sorted = 0;
	prep_sort(a, b);
	prep_stack_a(a, b);
	cheapest = find_cheapest(*a);
	stack_len_a = ft_stack_size(*a);
	while (stack_len_a-- > 3)
	{
		ft_printf("Stack a : \n");
		print_stack(*a);
		ft_printf("\nStack b : \n");
		print_stack(*b);
		printf("for nb = %d\n", (*a)->nb);
		printf("	target = %d\n", (*a)->target_node->nb);
		printf("	target cost : %d\n", (*a)->target_cost);
		a_and_target_to_top(a, cheapest, b);
		ft_printf("Stack a post top: \n");
		print_stack(*a);
		ft_printf("\nStack b post top: \n");
		print_stack(*b);
		push_a(a, b);
		if ((*b)->nb == find_min(*b)->nb)
			rotate_b(b);
		index_in_stack(*a);
		index_in_stack(*b);
		target_cost(*a, *b);

		// RE-CALCUL target_cost
	}
}

t_stack	*find_node(t_stack *lst, int nb)
{
	t_stack	*stack;

	stack = lst;
	while (stack->nb != nb)
		stack = stack->next;
	return (stack);
}

		// t_stack *lst2 = *a;
		// while (lst2)
		// {
		// 	ft_printf("\n");
		// 	ft_printf("Stack a : \n");
		// 	print_stack(lst2);
		// 	ft_printf("\nStack b : \n");
		// 	print_stack(*b);
		// 	printf("for nb = %d\n", lst2->nb);
		// 	printf("	target = %d\n", lst2->target_node->nb);
		// 	printf("	index : %d\n", lst2->index);
		// 	printf("	cost : %d\n", lst2->total_cost);
		// 	printf("	target cost : %d\n", lst2->target_cost);

		// 	printf("	cheapest : %d\n", lst2->is_cheapest);

		// 	lst2 = lst2->next;
		// }