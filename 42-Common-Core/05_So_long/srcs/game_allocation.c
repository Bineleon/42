/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:48:35 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 17:41:20 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *game, t_map *map)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->current_img_char = NULL;
	game->textures[0] = NULL;
	game->alpha[0] = NULL;
	game->num[0] = NULL;
	game->map_copy = NULL;
	game->collected = 0;
	game->player_steps = 0;
	game->map = map;
}

t_data	*allocate_game(t_map *map)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
	{
		ft_printf(RED);
		ft_putstr_fd("Error allocating memory", 2);
		ft_printf(RESET);
		free_map(map);
		free(map);
		exit(EXIT_FAILURE);
	}
	init_data(game, map);
	return (game);
}

void	*init_graphics(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		ft_printf(RED);
		ft_putstr_fd("Error initializing graphics\n", 2);
		ft_printf(RESET);
		exit(EXIT_FAILURE);
	}
	return (mlx_ptr);
}
