/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:21 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 19:25:09 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = init_b();
    line = NULL;
	if (ac > 1)
	{
		prep_main(ac, av, &a);
        line = get_next_line(0);
        if (!line && is_sorted(a))
            ft_putstr_fd("OK\n", 1);
        else if (!line && !is_sorted(a))
            ft_putstr_fd("KO\n", 1);
        else
            checker(&a, &b, line);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
