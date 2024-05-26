/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:40 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 19:25:19 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_main(int ac, char **av, t_stack **a)
{
	char	*joined_args;

	joined_args = NULL;
	check_empty_args(ac, av);
	joined_args = join_arguments(ac, av);
	validate_and_init_stack(&a, joined_args);
	free(joined_args);
	check_duplicate_in_stack(&a);
}

void	error_checker(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
