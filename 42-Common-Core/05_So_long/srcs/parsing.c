/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:04:10 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 21:26:09 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player_pos(t_map *map, char **map_cpy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == PLAYER)
			{
				map->player_pos_x = x;
				map->player_pos_y = y;
			}
			else if (map_cpy[y][x] == EXIT)
			{
				map->exit_pos_x = x;
				map->exit_pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	object_count(char square, int *collec, int *exit)
{
	if (square == COLLEC)
		(*collec)++;
	else if (square == EXIT)
		(*exit)++;
	else
		return ;
}

int	objs_are_reachable(t_map *map)
{
	if (map->ff_collec != map->collec || map->ff_exit != 1)
	{
		ft_putstr_fd("Unvalid map : unreachable collectible(s) or exit \n", 2);
		return (0);
	}
	return (1);
}

void	flood_fill(char **map_copy, t_map *map, int x, int y)
{
	while (map_copy[y] && map_copy[y][x])
	{
		if (map_copy[y][x] != WALL && map_copy[y][x] != 'F')
		{
			object_count(map_copy[y][x], &map->ff_collec, &map->ff_exit);
			map_copy[y][x] = 'F';
			if (x > 0)
				flood_fill(map_copy, map, x - 1, y);
			if (map_copy[y][x + 1])
				flood_fill(map_copy, map, x + 1, y);
			if (y > 0)
				flood_fill(map_copy, map, x, y - 1);
			if (map_copy[y + 1])
				flood_fill(map_copy, map, x, y + 1);
		}
		break ;
	}
}
