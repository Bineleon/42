/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:09:05 by neleon            #+#    #+#             */
/*   Updated: 2024/07/18 16:27:02 by neleon           ###   ########.fr       */
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

int open_map_file(char *av)
{
    int map_fd;

    map_fd = open(av, O_RDONLY);
    if (map_fd < 0)
    {
        ft_putstr_fd("Error opening file\n", 2);
        exit(EXIT_FAILURE);
    }
    return (map_fd);
}

char *read_first_line(int map_fd)
{
    char *line;

    line = get_next_line(map_fd, 0);
    if (!line || line[0] == '\n')
    {
        free_line(line);
        get_next_line(map_fd, 1);
        close(map_fd);
        exit(EXIT_FAILURE);
    }
    return line;
}

void validate_first_line(char *line, int map_fd)
{
    if (!line)
    {
        ft_putstr_fd("Invalid map file\n", 2);
        clean_map_reading(line, map_fd);
        exit(1);
    }
}

void calculate_map_size(t_data *game, t_map *map, int map_fd, char *line)
{
    map->col_count = map_len(line);
    while (line && line[0] != '\n')
    {
        if (map_len(line) != map->col_count)
        {
            ft_putstr_fd("Unvalid map format : the map should be a rectangle\n", 2);
            free(line);
			clean(game);
            // exit(1);
        }
        map->line_count += 1;
        free(line);
        line = get_next_line(map_fd, 0);
    }
}

void clean_map_reading(char *line, int map_fd)
{
    free_line(line);
    get_next_line(map_fd, 1);
    close(map_fd);
}

void map_size(char *av, t_map *map)
{
    int map_fd;
    char *line;

    map_fd = open_map_file(av);
    line = read_first_line(map_fd);
    validate_first_line(line, map_fd);
    calculate_map_size(map, map_fd, line);
    clean_map_reading(line, map_fd);
}

// void	map_size(char *av, t_map *map)
// {
// 	char	*line;
// 	int		map_fd;

// 	map_fd = open(av, O_RDONLY);
// 	line = get_next_line(map_fd, 0);
// 	if (!line || line[0] == '\n')
// 	{
// 		free_line(line);
// 		get_next_line(map_fd, 1);
// 		close(map_fd);
// 		return ;
// 	}
// 	map->col_count = map_len(line);
// 	while (line && line[0] != '\n')
// 	{
// 		if (map_len(line) != map->col_count)
// 		{
// 			free(line);
// 			line = NULL;
// 			ft_putstr_fd("Wrong map format\n", 2);
// 			exit(1);
// 		}
// 		map->line_count += 1;
// 		free(line);
// 		line = NULL;
// 		line = get_next_line(map_fd, 0);
// 	}
// 	free_line(line);
// 	get_next_line(map_fd, 1);
// 	close(map_fd);
// }

char	**map_cpy(int map_fd, t_map *map)
{
	char	*line;
	char	**map_copy;
	int		i;

	i = 0;
	line = NULL;
	map_copy = NULL;
	map_copy = (char **)malloc((map->line_count + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map->map = (char **)malloc((map->line_count + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
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
		printf("%s\n", map->map[i]);
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
