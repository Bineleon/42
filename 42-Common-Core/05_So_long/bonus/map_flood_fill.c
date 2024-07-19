/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:07 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 18:58:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
