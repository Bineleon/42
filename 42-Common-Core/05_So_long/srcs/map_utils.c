/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:09:05 by neleon            #+#    #+#             */
/*   Updated: 2024/07/18 19:46:26 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map *map)
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

int	map_len(char *line)
{
	int	count;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	return (count);
}

int	open_map_file(char *av)
{
	int	map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

char	*read_first_line(int map_fd, t_data *game)
{
	char	*line;

	line = get_next_line(map_fd, 0);
	if (line[0] != WALL)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		clean(game);
	}
	if (!line)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		exit(EXIT_FAILURE);
	}
	return (line);
}

void	validate_first_line(char *line, int map_fd)
{
	if (!line)
	{
		ft_putstr_fd("Invalid map file\n", 2);
		clean_map_reading(line, map_fd);
		exit(1);
	}
}

void	calculate_map_size(t_data *game, t_map *map, int map_fd, char *line)
{

	map->col_count = map_len(line);
	while (line && line[0] != '\n')
	{
		if (map_len(line) != map->col_count)
		{
			free_line(line);
			printf("free line2\n");
			get_next_line(map_fd, 1);
			ft_putstr_fd("Unvalid map format : the map should be a rectangle\n", 2);
			clean(game);
		}
		map->line_count += 1;
		free(line);
		printf("free line0\n");
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

void	clean_map_reading(char *line, int map_fd)
{
	line = NULL;
	get_next_line(map_fd, 1);
	close(map_fd);
}

void	map_size(char *av, t_map *map, t_data *game)
{
	int		map_fd;
	char	*line;

	map_fd = open_map_file(av);
	line = read_first_line(map_fd, game);
	validate_first_line(line, map_fd);
	calculate_map_size(game, map, map_fd, line);
	printf("ICI map_size\n\n");
	clean_map_reading(line, map_fd);
}

char	**map_cpy(int map_fd, t_map *map, t_data *game)
{
	char	*line;
	char	**map_copy;
	int		i;

	i = 0;
	line = NULL;
	map_copy = NULL;
	map_copy = (char **)malloc((map->line_count + 1) * sizeof(char *));
	if (!map_copy)
	{
		clean(game);
		return (NULL);
	}
	map->map = (char **)malloc((map->line_count + 1) * sizeof(char *));
	if (!map->map)
	{
		find_size_and_free_map(map_copy);
		return (NULL);
	}
	line = get_next_line(map_fd, 0);
	if (!line || line[0] != WALL)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		free(map_copy);
		return (NULL);
	}
	while (line)
	{
		map->map[i] = ft_strdup(line);
		map_copy[i] = ft_strdup(line);
		map->map[i][map->col_count] = '\0';
		map_copy[i][map->col_count] = '\0';
		free(line);
		line = get_next_line(map_fd, 0);
		i++;
	}
	map->map[i] = NULL;
	map_copy[i] = NULL;
	if (line)
		free_line(line);
	get_next_line(map_fd, 1);
	return (close(map_fd), map_copy);
}
