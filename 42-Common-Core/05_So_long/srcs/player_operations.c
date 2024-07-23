/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:29 by neleon            #+#    #+#             */
/*   Updated: 2024/07/23 14:51:10 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_player_position(t_data *game, int x_old, int y_old)
{
	game->map->map[y_old][x_old] = FLOOR;
	if (game->map->player_pos_y == game->map->exit_pos_y
		&& game->map->player_pos_x == game->map->exit_pos_x
		&& game->collected == game->map->collec)
		clean(game);
	game->map->map[game->map->player_pos_y][game->map->player_pos_x] = PLAYER;
}

void	move_up(t_data *game)
{
	int	y_old;
	int	x_old;

	y_old = game->map->player_pos_y;
	x_old = game->map->player_pos_x;
	if (game->map->map[y_old - 1][x_old] != WALL)
	{
		check_collectible(game, y_old - 1, x_old);
		game->map->player_pos_y -= 1;
		count_and_display_steps(game);
	}
}

void	move_down(t_data *game)
{
	int	y_old;
	int	x_old;

	y_old = game->map->player_pos_y;
	x_old = game->map->player_pos_x;
	if (game->map->map[y_old + 1][x_old] != WALL)
	{
		check_collectible(game, y_old + 1, x_old);
		game->map->player_pos_y += 1;
		count_and_display_steps(game);
	}
}

void	move_left(t_data *game)
{
	int	y_old;
	int	x_old;

	y_old = game->map->player_pos_y;
	x_old = game->map->player_pos_x;
	if (game->map->map[y_old][x_old - 1] != WALL)
	{
		check_collectible(game, y_old, x_old - 1);
		game->map->player_pos_x -= 1;
		count_and_display_steps(game);
	}
}

void	move_right(t_data *game)
{
	int	y_old;
	int	x_old;

	y_old = game->map->player_pos_y;
	x_old = game->map->player_pos_x;
	if (game->map->map[y_old][x_old + 1] != WALL)
	{
		check_collectible(game, y_old, x_old + 1);
		game->map->player_pos_x += 1;
		count_and_display_steps(game);
	}
}
