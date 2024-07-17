/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 15:47:32 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_top_down_wall(char *line, int *col_count)
{
	int	i;

	i = 0;
	while (i < *col_count)
	{
		if (line[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_middle_wall(char *line, int col_count, t_map **map)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	if (line[0] != WALL || line[col_count - 1] != WALL)
		return (0);
	while (i < col_count)
	{
		if (line[i] != PLAYER && line[i] != WALL && line[i] != FLOOR
			&& line[i] != COLLEC && line[i] != EXIT)
			return (0);
		if (line[i] == PLAYER)
			(*map)->player++;
		else if (line[i] == COLLEC)
			(*map)->collec++;
		else if (line[i] == EXIT)
			(*map)->exit++;
		i++;
	}
	return (1);
}

char *read_first_line_map(int map_fd)
{
    char *line;

    line = get_next_line(map_fd, 0);
    if (!line)
    {
        free_line(line);
        get_next_line(map_fd, 1);
        close(map_fd);
    }
    return line;
}

int validate_top_wall(char *line, t_map **map, int map_fd)
{
    if (!is_valid_top_down_wall(line, &(*map)->col_count))
    {
        free(line);
        get_next_line(map_fd, 1);
        close(map_fd);
        return 0;
    }
    return 1;
}

int validate_middle_line(char *line, t_map **map, int map_fd, int i)
{
    if (!is_valid_middle_wall(line, (*map)->col_count, map))
    {
        free_line(line);
        get_next_line(map_fd, 1);
        close(map_fd);
        return 0;
    }
    if (i == (*map)->line_count - 1)
    {
        if (!is_valid_top_down_wall(line, &(*map)->col_count))
        {
            free_line(line);
            get_next_line(map_fd, 1);
            close(map_fd);
            return 0;
        }
    }
    return 1;
}

int is_valid_format(int map_fd, t_map **map)
{
    char *line;
    int i;

    i = 0;
    line = read_first_line_map(map_fd);
    if (!line)
        return (-1);
    if (!validate_top_wall(line, map, map_fd))
        return (0);
    while (i <= (*map)->line_count - 1 && line[0] != '\n')
    {
        if (!validate_middle_line(line, map, map_fd, i))
            return (0);
        free(line);
        line = get_next_line(map_fd, 0);
        i++;
    }
    free_line(line);
    get_next_line(map_fd, 1);
    return (1);
}

int	is_valid_obj_count(t_map *map)
{
	if (map->player != 1 || map->exit != 1)
		return (0);
	if (map->collec < 1)
		return (0);
	return (1);
}

int	is_valid_map(int map_fd, t_map **map)
{
	if (!is_valid_format(map_fd, map) || !is_valid_obj_count(*map))
		return (0);
	return (1);
}
