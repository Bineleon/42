/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:34:38 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/17 21:27:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_win(t_data *game)
{
	int	win_x_size;
	int	win_y_size;

	win_x_size = game->map->col_count * IMG_SIZE;
	win_y_size = (game->map->line_count + 1) * IMG_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, win_x_size, win_y_size,
			"Peaceful Pete & the mushroom quest");
	if (!game->win_ptr)
	{
		clean(game);
	}
	display_map(game, -1, -1, 0);
}

void	img_to_win(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	update_player_position(t_data *game, int x_old, int y_old)
{
	game->map->map[y_old][x_old] = FLOOR;
	if (game->map->player_pos_y == game->map->exit_pos_y
		&& game->map->player_pos_x == game->map->exit_pos_x
		&& game->collected == game->map->collec)
	{
		printf("ICI update_player_pos\n");
		clean(game);
	}
	game->map->map[game->map->player_pos_y][game->map->player_pos_x] = PLAYER;
}

void	draw_tile(t_data *game, char tile, int x, int y)
{
	if (tile == WALL)
		img_to_win(game, game->textures[1], x * IMG_SIZE, (y + 1) * IMG_SIZE);
	else if (tile == PLAYER)
		img_to_win(game, game->current_img_char, x * IMG_SIZE, (y + 1)
			* IMG_SIZE);
	else if (x == game->map->exit_pos_x && y == game->map->exit_pos_y)
	{
		if (game->map->collec == game->collected)
		{
			ft_printf("\033[1;32m\e[5mPeaceful Pete collected\e[0m\033[0m");
			ft_printf("\033[1;32m\e[5m all the mushrooms 🍄 \e[0m\033[0m");
			ft_printf("\033[1;32m\e[5mtime to go back to the van !\e[0m\033[0m\n");
			img_to_win(game, game->textures[5], x * IMG_SIZE, (y + 1)
				* IMG_SIZE);
		}
		else
			img_to_win(game, game->textures[0], x * IMG_SIZE, (y + 1)
				* IMG_SIZE);
	}
	else if (tile == FLOOR)
		img_to_win(game, game->textures[0], x * IMG_SIZE, (y + 1) * IMG_SIZE);
	else if (tile == COLLEC)
		img_to_win(game, game->textures[2], x * IMG_SIZE, (y + 1) * IMG_SIZE);
}

void	draw_line(t_data *game, int y)
{
	int		x;
	char	tile;

	x = 0;
	while (x < game->map->col_count)
	{
		tile = game->map->map[y][x];
		draw_tile(game, tile, x, y);
		x++;
	}
}

void	display_map(t_data *game, int x_old, int y_old, int update)
{
	int	y;

	y = 0;
	display_header(game);
	if (update)
		update_player_position(game, x_old, y_old);
	while (y < game->map->line_count)
	{
		draw_line(game, y);
		y++;
	}
}
