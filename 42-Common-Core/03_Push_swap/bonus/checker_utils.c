/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:12:40 by neleon            #+#    #+#             */
/*   Updated: 2024/05/29 00:32:28 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_main(int ac, char **av, t_stack **a, t_stack **b)
{
	char	*joined_args;

	joined_args = NULL;
	check_empty_args(ac, av);
	joined_args = join_arguments(ac, av);
	validate_and_init_stack(a, joined_args);
	free(joined_args);
    if (check_duplicate_in_stack(*a) || is_not_int(*a))
    	error_checker(a, b, NULL);
}

void	error_checker(t_stack **a, t_stack **b, char **line)
{
	free_stack(a);
	free_stack(b);
	get_next_line(0, 1);
	ft_putstr_fd("Error\n", 2);
	if (!line)
		exit(1);
	free(*line);
	*line = NULL;
	exit(1);
}
