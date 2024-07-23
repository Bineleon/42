/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:44 by neleon            #+#    #+#             */
/*   Updated: 2024/07/23 15:02:35 by neleon           ###   ########.fr       */
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
		ft_printf(RED);
		ft_putstr_fd("Error allocating memory", 2);
		ft_printf(RESET);
		exit(EXIT_FAILURE);
	}
	init_map(map);
	return (map);
}

char	*read_first_line_map(int map_fd, t_data *game)
{
	char	*line;

	line = get_next_line(map_fd, 0);
	if (!line || !line[0])
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		ft_printf(RED);
		ft_putstr_fd("Invalid map file\n", 2);
		ft_printf(RESET);
		clean_map_reading(line, map_fd);
		if (game)
			clean(game);
	}
	return (line);
}
