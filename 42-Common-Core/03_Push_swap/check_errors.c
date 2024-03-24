/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:47:33 by neleon            #+#    #+#             */
/*   Updated: 2024/03/24 23:53:36 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	not_digit(char *str)
{
	int	i;

	i = 0;
	if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
		return (1);
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[1]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int is_duplicate(t_stack *stack_a, int nb)
{
	if (!stack_a)
		return (0);
	while(stack_a)
	{
		if (stack_a->nb == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}