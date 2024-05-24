/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:57:14 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 16:49:08 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*joined_args;

	a = NULL;
	b = init_b();
	joined_args = NULL;
	if (ac > 1)
	{
		check_empty_args(ac, av);
		joined_args = join_arguments(ac, av);
		validate_and_init_stack(&a, joined_args);
		free(joined_args);
		check_dup_and_sort(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
