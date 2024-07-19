/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:48:35 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 19:06:57 by neleon           ###   ########.fr       */
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
		ft_putstr_fd("Error allocating memory", 2);
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
		ft_putstr_fd("Error initializing graphics\n", 2);
		exit(EXIT_FAILURE);
	}
	return (mlx_ptr);
}