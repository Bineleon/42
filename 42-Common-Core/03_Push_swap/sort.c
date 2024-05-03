/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/05/03 18:15:03 by neleon           ###   ########.fr       */
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

void	sort_a(t_stack **a, t_stack **b)
{
    int		stack_len_b;
    int     i;
    t_stack	*cheapest;
	t_stack	*tmp;

    printf("SORT_A START\n");
	stack_len_b = ft_stack_size(*b);
    i = 0;
	while (*b)
	{
		printf("NEW START\n");
    	prep_stack_b(b, a);
        cheapest = find_cheapest(*b);
		tmp = *b;
		while (tmp)
		{
			printf("current : %d total cost : %d\n", tmp->nb, tmp->total_cost);
			tmp = tmp->next;
		}
        ft_printf("\nStack a FIRST : \n");
		print_stack(*a);
		ft_printf("\nStack b FIRST: \n");
		print_stack(*b);
        printf("cheapest : %d\n", cheapest->nb);
		printf("cheapest total cost : %d\n", cheapest->total_cost);
		printf("\n\nfor nb = %d\n", (cheapest)->nb);
		printf("cheapest is_in_top? : %d\n", cheapest->is_in_top);
		printf("target is_in_top? : %d\n", cheapest->target_node->is_in_top);
        printf("nb->target = %d\n", (cheapest)->target_node->nb);
		printf("is_cheapest? = %d\n", (cheapest)->is_cheapest);
		// ft_printf("Stack a : \n");
		// print_stack(*a);
		// ft_printf("\nStack b : \n");
		// print_stack(*b);
		// printf("	target = %d\n", (*a)->target_node->nb);
		// printf("	target cost : %d\n", (*a)->target_cost);
		b_and_target_to_top(b, cheapest, a);
		ft_printf("Stack a post top: \n");
		print_stack(*a);
		ft_printf("\nStack b post top: \n");
		print_stack(*b);
		push_b(b, a);
		if ((*a) == find_max(*a))
			rotate_a(a);
		// if (*b)
        // 	prep_stack_b(b, a);
		// if ((*b)->nb == find_min(*b)->nb)
		// 	rotate_b(b);
		// index_in_stack(a);
		// index_in_stack(b);
		// total_cost(*a, *b);
		// RE-CALCUL target_cost
        // i++;
	}
	
}


void	sort_b(t_stack **a, t_stack **b)
{
	// int		is_sorted;
	int		stack_len_a;
	t_stack	*cheapest;

	// is_sorted = 0;
    printf("SORT B\n");
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
		// printf("	target cost : %d\n", (*a)->target_cost);
		a_and_target_to_top(a, cheapest, b);
		ft_printf("Stack a post top: \n");
		print_stack(*a);
		ft_printf("\nStack b post top: \n");
		print_stack(*b);
		push_a(a, b);
		// if ((*b)->nb == find_min(*b)->nb)
		// 	rotate_b(b);
        prep_stack_a(a, b);
		// index_in_stack(a);
		// index_in_stack(b);
		// total_cost(*a, *b);
		// RE-CALCUL target_cost
	}
}

void	last_sort(t_stack **a)
{
	// t_stack	*min;
	// int stack_len;
	// stack_len = ft_stack_size(a);

	// min = find_min(*a);
	while((*a)->nb != find_min(*a)->nb)
	{
		index_in_stack(a);
		if ((*a)->is_in_top)
			rotate_a(a);
		else
			rev_rotate_a(a);
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
