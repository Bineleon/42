/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:12 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 23:45:48 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	calculate_map_size(t_data *game, t_map *map, int map_fd, char *line)
{
	map->col_count = map_len(line);
	while (line && line[0] != '\n')
	{
		
		if (map_len(line) != map->col_count)
		{
			ft_putstr_fd("\033[1;31mUnvalid map format :\033[0m", 2);
			ft_putstr_fd("\033[1;31m the map should be a rectangle\033[0m\n",
				2);
			free_line(line);
			clean_map_reading(line, map_fd);
			clean(game);
		}
		map->line_count += 1;
		free(line);
		line = get_next_line(map_fd, 0);
		if (!line)
			clean_map_reading(line, map_fd);
	}
	clean_map_reading(line, map_fd);
	if (!check_map_limit_size(map))
	{
		clean_map_reading(line, map_fd);
		clean(game);
	}
}

void	map_size(char *av, t_map *map, t_data *game)
{
	int		map_fd;
	char	*line;

	map_fd = open_map_file(av, game);
	line = read_first_line(map_fd, game);
	validate_first_line(line, map_fd, game);
	calculate_map_size(game, map, map_fd, line);
	clean_map_reading(line, map_fd);
}
