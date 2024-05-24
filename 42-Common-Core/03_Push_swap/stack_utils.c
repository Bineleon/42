/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:03:42 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 16:52:20 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stack(t_stack **stack_a, char *joined_args)
{
	char	**split_args;
	int		i;

	split_args = ft_split(joined_args, ' ');
	i = 0;
	while (split_args[i])
	{
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(split_args[i])));
		i++;
	}
	free_malloc(split_args, ft_count_words(joined_args, ' '));
}

t_stack	*init_b(void)
{
	return (NULL);
}

void	validate_and_init_stack(t_stack **a, char *joined_args)
{
	if (!joined_args || !is_valid_number_string(joined_args))
	{
		free(joined_args);
		print_error(a);
	}
	init_stack(a, joined_args);
}

void	check_dup_and_sort(t_stack **a, t_stack **b)
{
	if (is_duplicate_in_stack(*a) || is_not_int(*a))
		print_error(a);
	if (!is_sorted(*a))
	{
		if (ft_stack_size(*a) == 3)
			sort_three_a(a);
		else
			sort_stack(a, b);
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;
	int		first_seen;

	if (!stack)
		return ;
	first_seen = 1;
	tmp = stack;
	while (tmp)
	{
		nbr = tmp->nb;
		if (first_seen == 1)
		{
			ft_printf("%d", nbr);
			first_seen = 0;
		}
		else if (first_seen == 0)
			ft_printf(" %d", nbr);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
