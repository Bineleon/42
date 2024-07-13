/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:34:38 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/13 18:20:24 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	assign_img_ptr(t_data *game)
{
	int	img_size;

	img_size = IMG_SIZE;
		printf("\nICI assign_img_ptr\n");
	game->ptr_img_char_left = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/character_left.xpm", &img_size, &img_size);
	if (!game->ptr_img_char_left)
	{
		fprintf(stderr, "Error loading image: character_left.xpm\n");
		exit(EXIT_FAILURE);
	}
	printf("\nICI assign_img_ptr\n");
	game->ptr_img_char_right = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/character_right.xpm", &img_size, &img_size);
	if (!game->ptr_img_char_right)
	{
		fprintf(stderr, "Error loading image: character_right.xpm\n");
		exit(EXIT_FAILURE);
	}
	game->ptr_img_collec = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/collec.xpm", &img_size, &img_size);
	if (!game->ptr_img_collec)
	{
		fprintf(stderr, "Error loading image: collec.xpm\n");
		exit(EXIT_FAILURE);
	}
	game->ptr_img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/exit.xpm", &img_size, &img_size);
	if (!game->ptr_img_exit)
	{
		fprintf(stderr, "Error loading image: exit.xpm\n");
		exit(EXIT_FAILURE);
	}
	game->ptr_img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/floor.xpm", &img_size, &img_size);
	if (!game->ptr_img_floor)
	{
		fprintf(stderr, "Error loading image: floor.xpm\n");
		exit(EXIT_FAILURE);
	}
	game->ptr_img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/wall.xpm", &img_size, &img_size);
	if (!game->ptr_img_wall)
	{
		fprintf(stderr, "Error loading image: wall.xpm\n");
		exit(EXIT_FAILURE);
	}
}

void	init_win(t_data *game)
{
	int	win_x_size;
	int win_y_size;

	win_x_size = game->map->col_count * IMG_SIZE;
	win_y_size = game->map->line_count * IMG_SIZE;
	printf("/nICI init_win\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, win_x_size, win_y_size, "So_long baby");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		return;
	}
	display_map(game);
}

void	img_to_win(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void display_new_map(t_data *game, int x_old, int y_old)
{
    char tile;
    int x;
    int y;

    y = 0;
    tile = 0;
    game->map->map[y_old][x_old] = FLOOR;
    game->map->map[game->map->player_pos_y][game->map->player_pos_x] = PLAYER;

    while (y < game->map->line_count)
    {
        x = 0;
        while (x < game->map->col_count)
        {
            tile = game->map->map[y][x];
            if (tile == WALL)
                img_to_win(game, game->ptr_img_wall, x * IMG_SIZE, y * IMG_SIZE);
            else if (tile == FLOOR)
                img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, y * IMG_SIZE);
            else if (tile == PLAYER)
                img_to_win(game, game->ptr_img_char_right, x * IMG_SIZE, y * IMG_SIZE);
            else if (tile == COLLEC)
            {
                img_to_win(game, game->ptr_img_collec, x * IMG_SIZE, y * IMG_SIZE);
            }
            else if (tile == EXIT)
            {
                if (game->map->collec == game->collected)
                  img_to_win(game, game->ptr_img_exit, x * IMG_SIZE, y * IMG_SIZE);
                else
                  img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, y * IMG_SIZE);
            }
            x++;
        }
        y++;
    }
}


void display_map(t_data *game)
{
    int x;
    int y;
    char tile;

    y = 0;
    tile = 0;
	  printf("\nICI display_map\n");
    while (y < game->map->line_count)
    {
        x = 0;
        while (x < game->map->col_count)
        {
            tile = game->map->map[y][x];
            if (tile == WALL)
                img_to_win(game, game->ptr_img_wall, x * IMG_SIZE, y * IMG_SIZE);
            else if (tile == FLOOR || tile == EXIT)
                img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, y * IMG_SIZE);
            else if (tile == PLAYER)
            {
                img_to_win(game, game->ptr_img_char_right, x * IMG_SIZE, y * IMG_SIZE);
                game->map->player_pos_x = x;
                game->map->player_pos_y = y;
            }
            else if (tile == COLLEC)
                img_to_win(game, game->ptr_img_collec, x * IMG_SIZE, y * IMG_SIZE);
            x++;
        }
        y++;
    }
}
