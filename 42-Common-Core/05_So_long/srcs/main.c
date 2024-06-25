/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:53:10 by neleon            #+#    #+#             */
/*   Updated: 2024/06/25 23:37:15 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	if (ac != 2)
	{
		ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
		ft_printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
	}
	else if (ac == 2)
	{
		map_cpy(av[1]);
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			return (1);
		win_ptr = mlx_new_window (mlx_ptr, 300, 300, "So_long");
		if (!win_ptr)
			return (2);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
