/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:12 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 20:44:46 by neleon           ###   ########.fr       */
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
			free_line(line);
			get_next_line(map_fd, 1);
			ft_putstr_fd("Unvalid map format :", 2);
			ft_putstr_fd(" the map should be a rectangle\n", 2);
			clean(game);
		}
		map->line_count += 1;
		free(line);
		line = get_next_line(map_fd, 0);
		if (!line)
			free_line(line);
	}
	if (!check_map_limit_size(map))
	{
		close(map_fd);
		clean(game);
	}
}

void	map_size(char *av, t_map *map, t_data *game)
{
	int		map_fd;
	char	*line;

	map_fd = open_map_file(av, game);
	line = read_first_line(map_fd, game);
	validate_first_line(line, map_fd);
	calculate_map_size(game, map, map_fd, line);
	clean_map_reading(line, map_fd);
}

// char	**map_cpy(int map_fd, t_map *map, t_data *game)
// {
// 	char	*line;
// 	char	**map_copy;
// 	int		i;

// 	i = 0;
// 	line = NULL;
// 	map_copy = NULL;
// 	map_copy = (char **)malloc((map->line_count + 1) * sizeof(char *));
// 	if (!map_copy)
// 	{
// 		clean(game);
// 		return (NULL);
// 	}
// 	map->map = (char **)malloc((map->line_count + 1) * sizeof(char *));
// 	if (!map->map)
// 	{
// 		find_size_and_free_map(map_copy);
// 		return (NULL);
// 	}
// 	line = get_next_line(map_fd, 0);
// 	if (!line || line[0] != WALL)
// 	{
// 		free_line(line);
// 		get_next_line(map_fd, 1);
// 		close(map_fd);
// 		free(map_copy);
// 		return (NULL);
// 	}
// 	while (line)
// 	{
// 		map->map[i] = ft_strdup(line);
// 		map_copy[i] = ft_strdup(line);
// 		map->map[i][map->col_count] = '\0';
// 		map_copy[i][map->col_count] = '\0';
// 		free(line);
// 		line = get_next_line(map_fd, 0);
// 		i++;
// 	}
// 	map->map[i] = NULL;
// 	map_copy[i] = NULL;
// 	if (line)
// 		free_line(line);
// 	get_next_line(map_fd, 1);
// 	return (close(map_fd), map_copy);
// }
