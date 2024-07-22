/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:08 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 22:19:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	char	**malloc_map_cpy(t_data *game)
{
	char	**map_copy;

	map_copy = NULL;
	map_copy = (char **)malloc((game->map->line_count + 1) * sizeof(char *));
	if (!map_copy)
	{
		clean(game);
		return (NULL);
	}
	return (map_copy);
}

static char	**malloc_map(t_data *game)
{
	char	**map_copy;

	map_copy = NULL;
	map_copy = (char **)malloc((game->map->line_count + 1) * sizeof(char *));
	if (!map_copy)
	{
		find_size_and_free_map(map_copy);
		return (NULL);
	}
	return (map_copy);
}

static	void	copy_line(char *line, t_data *game, int *i, int map_fd)
{
	while (line)
	{
		game->map->map[*i] = ft_strdup(line);
		game->map_copy[*i] = ft_strdup(line);
		game->map->map[*i][game->map->col_count] = '\0';
		game->map_copy[*i][game->map->col_count] = '\0';
		free(line);
		line = get_next_line(map_fd, 0);
		*i += 1;
	}
}

void	map_cpy(int map_fd, t_map *map, t_data *game)
{
	char	*line;
	char	**map_copy;
	int		i;

	i = 0;
	line = NULL;
	map_copy = malloc_map_cpy(game);
	game->map_copy = map_copy;
	map->map = malloc_map(game);
	line = get_next_line(map_fd, 0);
	if (!line || line[0] != WALL)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		free(game->map_copy);
		return ;
	}
	copy_line(line, game, &i, map_fd);
	map->map[i] = NULL;
	game->map_copy[i] = NULL;
	get_next_line(map_fd, 1);
	close(map_fd);
}
