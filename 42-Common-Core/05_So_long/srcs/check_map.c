/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/07/11 19:54:24 by bineleon         ###   ########.fr       */
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
	{
		return (0);
	}
	while (i < col_count)
	{
		if (line[i] != PLAYER && line[i] != WALL && line[i] != PATH
			&& line[i] != COLLEC && line[i] != EXIT)
		{
			printf("ERROR obj col %d\n", i);
			return (0);
		}
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

int	is_valid_format(int map_fd, t_map **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map_fd, 0);
	if (!line)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		return (-1);
	}
	if (!is_valid_top_down_wall(line, &(*map)->col_count))
	{
		free(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		return (0);
	}
	printf("line_count :  % d\n", (*map)->line_count);
	while (i <= (*map)->line_count - 1 && line[0] != '\n')
	{
		// printf("while line_count :  % d\n", i);
		// printf("line : %s\n", line);
		if (!is_valid_middle_wall(line, (*map)->col_count, map))
		{
			printf("ERROR line %d\n", i);
			free_line(line);
			get_next_line(map_fd, 1);
			close(map_fd);
			return (0);
		}
        if (i == (*map)->line_count - 1)
            if (!is_valid_top_down_wall(line, &(*map)->col_count))
            {
                free_line(line);
				get_next_line(map_fd, 1);
				close(map_fd);
	 	        return (0);
            }
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
