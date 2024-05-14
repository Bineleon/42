/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:47:33 by neleon            #+#    #+#             */
/*   Updated: 2024/05/14 19:07:15 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	not_digit(char *str)
{
	int	i;

	i = 0;
	if (!(ft_isdigit(str[i]) || str[i] != '-' || str[i] != '+'))
		return (ft_printf("1 Not digit\n"), 1);
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[1]))
		return (ft_printf("2 Not digit\n"), 1);
	if (str[i] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_printf("Not digit\n"), 1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_stack *stack_a, int nb)
{
	int	first_seen;

	first_seen = 1;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->nb == nb && first_seen == 1)
			first_seen = 0;
		else if (stack_a->nb == nb && first_seen == 0)
			return (ft_printf("DUP\n"), 1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	is_not_int(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (ft_printf("NOT INT\n"), 1);
	return (0);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
