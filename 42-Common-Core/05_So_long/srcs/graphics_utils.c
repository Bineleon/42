/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:34:38 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/15 17:34:28 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	assign_img_ptr(t_data *game)
{
	int	img_size;

	img_size = IMG_SIZE;
	game->ptr_img_char_left = mlx_xpm_file_to_image(game->mlx_ptr, CHAR_L_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_char_left)
		exit(EXIT_FAILURE);
	game->ptr_img_char_right = mlx_xpm_file_to_image(game->mlx_ptr, CHAR_R_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_char_right)
		exit(EXIT_FAILURE);
	game->current_img_char = mlx_xpm_file_to_image(game->mlx_ptr, CHAR_R_PATH,
			&img_size, &img_size);
	if (!game->current_img_char)
		exit(EXIT_FAILURE);
	game->ptr_img_collec = mlx_xpm_file_to_image(game->mlx_ptr, COLLEC_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_collec)
		exit(EXIT_FAILURE);
	game->ptr_img_exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_exit)
		exit(EXIT_FAILURE);
	game->ptr_img_floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_floor)
		exit(EXIT_FAILURE);
	game->ptr_img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_PATH,
			&img_size, &img_size);
	if (!game->ptr_img_wall)
		exit(EXIT_FAILURE);
}

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
		free(game->mlx_ptr);
		return ;
	}
	display_map(game);
}

void	img_to_win(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	update_player_position(t_data *game, int x_old, int y_old)
{
	game->map->map[y_old][x_old] = FLOOR;
	if (game->map->map[game->map->player_pos_y][game->map->player_pos_x] == EXIT
		&& game->collected == game->map->collec)
		clean(game);
	game->map->map[game->map->player_pos_y][game->map->player_pos_x] = PLAYER;
}
void	draw_tile(t_data *game, char tile, int x, int y)
{
	if (tile == WALL)
		img_to_win(game, game->ptr_img_wall, x * IMG_SIZE, (y + 1) * IMG_SIZE);
	else if (tile == FLOOR)
		img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, (y + 1) * IMG_SIZE);
	else if (tile == PLAYER)
		img_to_win(game, game->current_img_char, x * IMG_SIZE, (y + 1)
			* IMG_SIZE);
	else if (tile == COLLEC)
		img_to_win(game, game->ptr_img_collec, x * IMG_SIZE, (y + 1)
			* IMG_SIZE);
	else if (tile == EXIT)
	{
		if (game->map->collec == game->collected)
		{
			ft_printf("\033[1;32m\e[5mPeaceful Pete finnaly got all the mushrooms 🍄 \e[0m\033[0m");
			ft_printf("\033[1;32m\e[5mtime to go back to the van !\e[0m\033[0m\n");
			img_to_win(game, game->ptr_img_exit, x * IMG_SIZE, (y + 1)
				* IMG_SIZE);
		}
		else
			img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, (y + 1)
				* IMG_SIZE);
	}
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

void	display_new_map(t_data *game, int x_old, int y_old)
{
	int	y;

	y = 0;
	display_header(game);
	update_player_position(game, x_old, y_old);
	while (y < game->map->line_count)
	{
		draw_line(game, y);
		y++;
	}
}

void	display_map(t_data *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	tile = 0;
	display_header(game);
	while (y < game->map->line_count)
	{
		x = 0;
		while (x < game->map->col_count)
		{
			tile = game->map->map[y][x];
			if (tile == WALL)
				img_to_win(game, game->ptr_img_wall, x * IMG_SIZE, (y + 1)
					* IMG_SIZE);
			else if (tile == FLOOR || tile == EXIT)
				img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, (y + 1)
					* IMG_SIZE);
			else if (tile == PLAYER)
			{
				img_to_win(game, game->ptr_img_char_right, x * IMG_SIZE, (y + 1)
					* IMG_SIZE);
				game->map->player_pos_x = x;
				game->map->player_pos_y = y;
			}
			else if (tile == COLLEC)
				img_to_win(game, game->ptr_img_collec, x * IMG_SIZE, (y + 1)
					* IMG_SIZE);
			x++;
		}
		y++;
	}
}
