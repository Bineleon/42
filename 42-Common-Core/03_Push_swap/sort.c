/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 18:56:36 by neleon           ###   ########.fr       */
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
    // int		stack_len_b;
    // int     i;
    t_stack	*cheapest;
	// t_stack	*tmp;

    // printf("SORT_A START\n");
	// stack_len_b = ft_stack_size(*b);
    // i = 0;
	while (*b)
	{
		// printf("NEW START\n");
    	prep_stack_b(b, a);
        cheapest = find_cheapest(*b);
		// tmp = *b;
		// while (tmp)
		// {
			// printf("current : %d total cost : %d\n", tmp->nb, tmp->total_cost);
		// 	tmp = tmp->next;
		// }
        // ft_printf("\nStack a FIRST : \n");
		// print_stack(*a);
		// ft_printf("\nStack b FIRST: \n");
		// print_stack(*b);
		// if (cheapest->nb == 18)
		// {
			// printf("cheapest : %d\n", cheapest->nb);
			// printf("\n\nfor nb = %d\n", (cheapest)->nb);
			// printf("cheapest total cost : %d\n", cheapest->total_cost);
			// printf("cheapest is_in_top? : %d\n", cheapest->is_in_top);
			// printf("index = %d\n", cheapest->index);
			// printf("target is_in_top? : %d\n", cheapest->target_node->is_in_top);
			// printf("nb->target = %d\n", (cheapest)->target_node->nb);
			// printf("is_cheapest? = %d\n", (cheapest)->is_cheapest);
			// ft_printf("Stack a : \n");
			// print_stack(*a);
			// ft_printf("\nStack b : \n");
			// print_stack(*b);
		// }		// ft_printf("Stack a post top: \n");
		// print_stack(*a);
		// ft_printf("\nStack b post top: \n");
		// print_stack(*b);
		// printf("	target = %d\n", (*a)->target_node->nb);
		// printf("	target cost : %d\n", (*a)->target_cost);
		b_and_target_to_top(b, cheapest, a);
		// if(cheapest)
		// ft_printf("Stack a post top: \n");
		// print_stack(*a);
		// ft_printf("\nStack b post top: \n");
		// print_stack(*b);
		push_b(b, a);
		// if ((*a) == find_max(*a))
		// 	rotate_a(a);
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

void sort_b(t_stack **a, t_stack **b)
{
    t_stack *current;
    int size;
    int seg;
    int segment;
    // int cur_nb;
    // int total;

    prep_stack_a(a);
    size = ft_stack_size(*a);
    seg = 1;
    while (seg <= 5)
    {
        current = *a;
        while (current && size > 3)
        {
            assign_cost_in_a(a);
            get_cheapest_by_segment(a, seg);
            segment = current->segment;
            // cur_nb = current->nb;
            // total = current->total_cost;
            // printf("cur->nb %d\n", cur_nb);
            // printf("cur->total_cost %d\n", total);
            if (segment == seg && current->is_cheapest)
            {
                node_to_top(a, current);
                push_a(a, b);
                current = *a;
                size--;
            }
            else
                current = current->next;
        }
        seg++;
    }
    // printf("stack A : \n");
    // print_stack(*a);
    // printf("stack B : \n");
    // print_stack(*b);
}

void	last_sort(t_stack **a)
{
	while((*a)->nb != find_min(*a)->nb)
	{
		index_in_stack(a);
		if (find_min(*a)->is_in_top)
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
			// ft_printf("\n");
			// ft_printf("Stack a : \n");
			// print_stack(lst2);
			// ft_printf("\nStack b : \n");
			// print_stack(*b);
			// printf("for nb = %d\n", lst2->nb);
			// printf("	target = %d\n", lst2->target_node->nb);
			// printf("	index : %d\n", lst2->index);
			// printf("	cost : %d\n", lst2->total_cost);
			// printf("	target cost : %d\n", lst2->target_cost);

			// printf("	cheapest : %d\n", lst2->is_cheapest);

		// 	lst2 = lst2->next;
		// }
