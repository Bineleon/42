/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/24 00:36:15 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack *lst)
{
	int		i;
	int		mid;
	t_stack	*stack;

	i = 0;
	stack = lst;
	mid = mid_stack(stack);
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->is_in_top = 1;
		else
			stack->is_in_top = 0;
		stack = stack->next;
		i++;
	}
}

void	prep_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_b;
	int		stack_len_a;
	int		i;

	i = 0;
	stack_len_a = ft_stack_size(*a);
	while (i++ < 2)
		push_a(a, b);
	min_b = find_min(*b);
	if ((*b)->nb == min_b->nb)
		swap_b(b);
	else if ((*b)->nb < (*b)->next->nb)
		swap_b(b);
	push_a(a, b);
	if ((*b)->nb < (*b)->next->nb)
		swap_b(b);
	if ((*b)->next->nb < (*b)->next->next->nb)
	{
		rev_rotate_b(b);
		swap_b(b);
	}
}

void	prep_stack_a(t_stack **a, t_stack **b)
{
	index_in_stack(*a);
	index_in_stack(*b);
	target_a_in_b(*a, *b);
	total_cost(*a, *b);
	target_cost(*a, *b);
	get_cheapest(*a);
}

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
		a_and_target_to_top(a, cheapest, b);
		ft_printf("Stack a post top: \n");
		print_stack(*a);
		ft_printf("\nStack b post top: \n");
		print_stack(*b);
		push_a(a, b);
		if ((*b)->nb == find_min(*b)->nb)
			rotate_b(b);

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