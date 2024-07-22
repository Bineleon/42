/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:44 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 22:35:13 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
