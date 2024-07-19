/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:25:51 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/19 19:52:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_and_display_steps(t_data *game)
{
	game->player_steps += 1;
	if (game->player_steps == 1)
		ft_printf("\033[1;35mPeaceful Pete took his first step 🥹\n\n\033[0m");
	else
		ft_printf("\033[1;35mPeaceful Pete walked %d steps\n\n\033[0m",
			game->player_steps);
}

void	check_collectible(t_data *game, int y, int x)
{
	if (game->map->map[y][x] == COLLEC)
		game->collected += 1;
}

int	handle_key(int key, t_data *game)
{
	int	x_old;
	int	y_old;

	x_old = game->map->player_pos_x;
	y_old = game->map->player_pos_y;
	if (key == XK_Escape)
		clean(game);
	else if (key == KEY_UP)
		move_up(game);
	else if (key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_LEFT)
	{
		game->current_img_char = game->textures[3];
		move_left(game);
	}
	else if (key == KEY_RIGHT)
	{
		game->current_img_char = game->textures[4];
		move_right(game);
	}
	display_map(game, x_old, y_old, 1);
	return (0);
}
