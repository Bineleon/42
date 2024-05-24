/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:22:31 by neleon            #+#    #+#             */
/*   Updated: 2024/05/24 17:15:19 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	*join_arguments(int ac, char **av)
{
	char	*joined_args;
	char	*temp;
	int		i;

	if (ac < 2)
		return (NULL);
	temp = NULL;
	joined_args = ft_strjoin("", av[1]);
	i = 2;
	while (i < ac)
	{
		temp = ft_strjoin(joined_args, " ");
		free(joined_args);
		joined_args = ft_strjoin(temp, av[i]);
		free(temp);
		i++;
	}
	return (joined_args);
}

void	check_empty_args(int ac, char **av)
{
	char	*arg;

	if (ac == 2)
	{
		arg = av[1];
		while (*arg)
		{
			if (*arg != ' ')
				return ;
			arg++;
		}
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
