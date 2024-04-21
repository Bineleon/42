/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:12 by neleon            #+#    #+#             */
/*   Updated: 2024/04/21 20:48:34 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	index_in_stack(t_stack *lst)
{
	int	i;
	int	mid;

	i = 0;
	mid = mid_stack(lst);
	if (!lst)
		return ;
	while (lst)
	{
		lst->index = i;
		if (i <= mid)
			lst->is_in_top = 1;
		else
			lst->is_in_top = 0;
		lst = lst->next;
		i++;
	}
}

void	get_cheapest(t_stack *a)
{
	int		cost;
	t_stack	*cheapest;

	cost = INT_MAX;
	cheapest = NULL;
	while (a)
	{
		if (a->moves_to_top < cost)
		{
			cheapest = a;
			cost = a->moves_to_top;	
		}
		a = a->next;
	}
	cheapest->is_cheapest = 1;
}


// void	a_and_target_to_top(t_stack *a, t_stack *b)
// {
// 	t_stack	*current_a;
// 	t_stack	*current_b;

// 	current_a = a;
// 	current_b = b;
// 	while (current_a)
// }

// void	a_and_target_to_top(t_stack *a, t_stack *b)
// {
// 	t_stack	*stack_a;
// 	t_stack	*target_b;
// 	int i;

// 	i = 0;
// 	stack_a = a;
// 	target_b = stack_a->target_node;
// 	moves_calcul(stack_a);
// 	moves_calcul(target_b);
// 	printf("target to top\n");
// 	if (stack_a->is_in_top && target_b->is_in_top)
// 	{
// 		printf("Rotate\n");
// 		while(i < stack_a->moves_to_top && i < target_b->moves_to_top)
// 		{
// 			rr(&a, &b);
// 			i++;
// 		}
// 		while (i < stack_a->moves_to_top)
// 		{
// 			rotate_a(&a);
// 			i++;
// 		}
// 		while (i < target_b->moves_to_top)
// 		{
// 			rotate_b(&b);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		printf("rev_Rotate\n");
// 		while(i < stack_a->moves_to_top && i < target_b->moves_to_top)
// 		{
// 			rrr(&a, &b);
// 			i++;
// 		}
// 		while (i < stack_a->moves_to_top)
// 		{
// 			rev_rotate_a(&a);
// 			i++;
// 		}
// 		while (i < target_b->moves_to_top)
// 		{
// 			rev_rotate_b(&b);
// 			i++;
// 		}
// 	}
// }

void	moves_calcul(t_stack *a, t_stack *b)
{
	t_stack	*stack_a;
	int		stack_len_a;
	int		stack_len_b;

	stack_a = a;
	stack_len_a = ft_stack_size(a);	
	stack_len_b = ft_stack_size(b);
	index_in_stack(a);
	index_in_stack(b);
	while (stack_a)
	{
		if (stack_a->is_in_top)
			stack_a->moves_to_top = stack_a->index;
		else
			stack_a->moves_to_top = stack_len_a - stack_a->index;
		if (stack_a->target_node->is_in_top)
            stack_a->moves_to_top += stack_a->target_node->index;
        else
            stack_a->moves_to_top += stack_len_b - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

// void	moves_calcul(t_stack *a, t_stack *b)
// {
// 	t_stack	*stack_a;
// 	int		stack_len_a;
// 	int		stack_len_b;

// 	stack_a = a;
// 	index_in_stack(stack_a);
// 	index_in_stack(b);
// 	stack_len_a = ft_stack_size(stack_a);
// 	stack_len_b = ft_stack_size(b);
// 	while (stack_a)
// 	{
// 		if (stack_a->is_in_top)
// 			stack_a->moves_to_top = stack_a->index;
// 		else
// 			stack_a->moves_to_top = stack_len_a - stack_a->index;
// 		if (stack_a->is_in_top && stack_a->target_node->is_in_top)
// 			stack_a->moves_to_top += stack_a->target_node->index;
// 		else if (stack_a->is_in_top && !(stack_a->target_node->is_in_top))
// 			stack_a->moves_to_top += stack_len_b - stack_a->target_node->index;
// 		else
// 			stack_a->moves_to_top += stack_len_b - stack_a->target_node->index;
// 		stack_a = stack_a->next;
// 	}
// }

// void	moves_calcul(t_stack *lst)
// {
// 	t_stack	*stack;
// 	int		stack_len;

// 	stack = lst;
// 	index_in_stack(stack);
// 	stack_len = ft_stack_size(stack);
// 	while (stack)
// 	{
// 		if (stack->is_in_top)
// 			stack->moves_to_top = stack->index;
// 		else
// 			stack->moves_to_top = stack_len - stack->index;
// 		stack = stack->next;
// 	}
// }

t_stack	*find_node(t_stack *lst, int nb)
{
	t_stack	*stack;

	stack = lst;
	while (stack->nb != nb)
		stack = stack->next;
	return (stack);
}

void	target_a_in_b(t_stack *a, t_stack *b)
{
	t_stack	*stack_a;
	t_stack	*min_node;
	t_stack	*max_node;

	stack_a = a;
	min_node = find_min(b);
	max_node = find_max(b);
	while (stack_a)
	{
		if ((stack_a->nb < min_node->nb) || (stack_a->nb > max_node->nb))
			stack_a->target_node = max_node;
		else
			find_target(a, b);
		stack_a = stack_a->next;
	}
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*stack_b;
	t_stack	*target;
	int		nb;

	while (a)
	{
		nb = INT_MIN;
		stack_b = b;
		while (stack_b)
		{
			if (a->nb > stack_b->nb && stack_b->nb > nb)
			{
				target = stack_b;
				nb = stack_b->nb;
			}
			stack_b = stack_b->next;
		}
		a->target_node = target;
		a = a->next;
	}
}

// void	target_b_in_a(t_stack *a, t_stack *b)
// {
// 	t_stack *stack_b;
// 	t_stack *min_node;
// 	t_stack *max_node;

// 	stack_b = b;
// 	min_node = find_min(a);
// 	max_node = find_max(a);
// 	while (stack_b)
// 	{
// 		if (stack_b->nb > max_node->nb)
// 			stack_b->target_node = min_node;
// 		else
// 			stack_b->target_node = max_node;
// 		stack_b = stack_b->next;
// 	}
// }