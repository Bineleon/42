/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:23:56 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 22:38:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker(t_stack **a, t_stack **b, char *line)
{
	while (line)
	{
		mv_read_exe(a, b, line);
		line = get_next_line(0);
	}
	if (!is_sorted(*a))
		ft_putstr_fd("KO\n", 1);
	else if (*b)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}
