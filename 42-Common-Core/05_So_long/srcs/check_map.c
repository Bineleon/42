/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/06/27 00:30:16 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_fd(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

int	is_valid_top_down_wall(char *line, int *col_count)
{
	while (line[*col_count] - 1)
	{
		if (line[*col_count] != WALL)
			return (1);
		*col_count += 1;
	}
	return (0);
}

int	map_len(char *line)
{
	int	count;

	count = 0;
	while (line[count -1])
		count++;
	return (count);
}

void	map_size(int map_fd, int *len, int *high)
{
	char	*line;
	
	line = get_next_line(map_fd, 0);
	if (!line)
		return ;
	*high = 1;
	*len = map_len(line);
	while (line)
	{
		if (map_len(line) != *len)
		{
			line = NULL;
			free(line);
			return;
		}
		*high += 1;
		free(line);
		get_next_line(map_fd, 0);
	}
	line = NULL;
	free(line);
}

int	is_valid_middle_wall(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	if (line[i] != WALL)
		return (0);
	while (line[i] - 1)
		i++;
	if (line[i] != WALL)
		return (0);
	return (1);
}

// int	is_valid_wall(int map_fd)
// {
// 	char	*line;
// 	int		col_count;

// 	col_count = 0;
// 	line = get_next_line(map_fd, 0);
// 	if (!line)
// 		return (-1);
// 	if (!is_valid_top_down_wall(line, &col_count))
// 	{
// 		free(line);
// 		return (0);
// 	}
// 	while ((line = get_next_line(map_fd, 0) != NULL))
// 	{
// 		if (!is_valid_middle_wall(line))
// 		{
// 			free(line);
// 			return (0);
// 		}
// 		free(line);
// 	}
// 	line = get_next_line(map_fd, 0);
// 	if (!is_valid_top_down_wall(line, &col_count))
// 	return (1);
// }

// void	count_objects(char *line, int *player, int *exit, int *collec)
// {
// 	if (*line == PLAYER)
// 		*player++;
// 	else if (*line == EXIT)
// 		*exit++;
// 	else if (*line == COLLEC)
// 		*collec++;
// }

// int	count_lines(int map_fd, char *map)
// {
// 	int		line_count;
// 	char	*line;

// 	line_count = 0;
// 	line = get_next_line(map_fd, 0);
// 	while (line)
// 		line_count++;
// 	return (line_count);
// }
// int	is_valid_map(int map_fd, t_map *map)
// {
// 	char	*line;

// 	line = get_next_line(map_fd, 0);
// 	if (!is_valid_wall_line(line))
// 		return (0);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(map_fd, 0);
// 		if (line)
// 			count_objects(line, &map->player, &map->exit, &map->collec);
// 	}
// 	if (map->player = !1 || map->exit != 1)
// 		return (0);
// 	if (map->collec < 1)
// 		return (0);
// 	return (1);
// }

// char	**map_cpy(int map_fd)
// {
// 	int	map_fd;
// }
