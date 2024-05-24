/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:47:33 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 17:27:24 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_duplicate_in_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->nb == runner->nb)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_number_string(char *str)
{
	int	i;

	i = 0;
	if (!(ft_isdigit(str[i]) || str[i] != '-' || str[i] != '+'))
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !ft_isdigit(str[1]))
		return (0);
	if (str[0] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-' && str[i - 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_not_int(t_stack *stack)
{
	while (stack)
	{
		if (stack->nb > INT_MAX || stack->nb < INT_MIN)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	print_error(t_stack **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
