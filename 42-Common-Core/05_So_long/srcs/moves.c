/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:25:51 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/13 19:34:12 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_collectible(t_data *game, int y, int x)
{
    if (game->map->map[y][x] == COLLEC)
        game->collected += 1;
}

void move_up(t_data *game)
{
    int y_old = game->map->player_pos_y;
    int x_old = game->map->player_pos_x;

    if (game->map->map[y_old - 1][x_old] != WALL)
    {
        check_collectible(game, y_old - 1, x_old);
        game->map->player_pos_y -= 1;
    }
}

void move_down(t_data *game)
{
    int y_old = game->map->player_pos_y;
    int x_old = game->map->player_pos_x;

    if (game->map->map[y_old + 1][x_old] != WALL)
    {
        check_collectible(game, y_old + 1, x_old);
        game->map->player_pos_y += 1;
    }
}

void move_left(t_data *game)
{
    int y_old = game->map->player_pos_y;
    int x_old = game->map->player_pos_x;

    if (game->map->map[y_old][x_old - 1] != WALL)
    {
        check_collectible(game, y_old, x_old - 1);
        game->map->player_pos_x -= 1;
    }
}

void move_right(t_data *game)
{
    int y_old = game->map->player_pos_y;
    int x_old = game->map->player_pos_x;

    if (game->map->map[y_old][x_old + 1] != WALL)
    {
        check_collectible(game, y_old, x_old + 1);
        game->map->player_pos_x += 1;
    }
}

int handle_key(int key, t_data *game)
{
    int x_old = game->map->player_pos_x;
    int y_old = game->map->player_pos_y;

    printf("ICI handle_key\n");
    if (key == XK_Escape)
        clean(game);
    else if (key == KEY_UP)
        move_up(game);
    else if (key == KEY_DOWN)
        move_down(game);
    else if (key == KEY_LEFT)
        move_left(game);
    else if (key == KEY_RIGHT)
        move_right(game);
    // mlx_clear_window(game->mlx_ptr, game->win_ptr);
    display_new_map(game, x_old, y_old);
    return (0);
}
