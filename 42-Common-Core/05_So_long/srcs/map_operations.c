/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:44 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 20:03:32 by neleon           ###   ########.fr       */
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

static void	init_map(t_map *map)
{
	map->line_count = 0;
	map->col_count = 0;
	map->player = 0;
	map->collec = 0;
	map->exit = 0;
	map->ff_collec = 0;
	map->ff_exit = 0;
	map->player_pos_y = 0;
	map->player_pos_x = 0;
	map->exit_pos_y = 0;
	map->exit_pos_x = 0;
	map->map = NULL;
}

t_map	*allocate_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error allocating memory", 2);
		exit(EXIT_FAILURE);
	}
	init_map(map);
	return (map);
}

char	*read_first_line_map(int map_fd)
{
	char	*line;

	line = get_next_line(map_fd, 0);
	if (!line)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
	}
	return (line);
}
