/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:04:45 by neleon            #+#    #+#             */
/*   Updated: 2024/03/24 23:52:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int ac, char **av)
{
	int i;
	t_stack *a = NULL;
	i = 1;
	
	if (ac > 1)
	{

		if (ac == 2)
		{
			// split
		}	
		else if (ac > 2)
		{
			init_stack(&a, av);
			while (i <= ac)
			{
				if(not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i])))
					print_error();
				i++;
			}
		}
	}
	return (0);
}