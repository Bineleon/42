/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:29 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 16:43:35 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_player_position(t_data *game, int x_old, int y_old)
{
	game->map->map[y_old][x_old] = FLOOR;
	if (game->map->player_pos_y == game->map->exit_pos_y
		&& game->map->player_pos_x == game->map->exit_pos_x
		&& game->collected == game->map->collec)
	{
		clean(game);
	}
	game->map->map[game->map->player_pos_y][game->map->player_pos_x] = PLAYER;
}