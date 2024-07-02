/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/06/28 23:52:30 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_fd(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

int	map_len(char *line)
{
	int	count;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	return (count);
}

void	map_size(char *av, t_map *map)
{
	char	*line;
	int		map_fd;

	map_fd = open(av, O_RDONLY);
	line = get_next_line(map_fd, 0);
	if (!line)
		return ;
	map->col_count = map_len(line);
	while (line && line[0] != '\n')
	{
		if (map_len(line) != map->col_count)
		{
			free(line);
			line = NULL;
			ft_putstr_fd("Wrong map format\n", 2);
			exit(1);
		}
		map->line_count += 1;
		free(line);
		line = NULL;
		line = get_next_line(map_fd, 0);
	}
	free_line(line);
	get_next_line(map_fd, 1);
	close(map_fd);
}

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
	line = get_next_line(map_fd, 0);
	if (!line)
		return (NULL);
	while (line)
	{
		map_copy[i] = ft_strdup(line);
		map_copy[i][map->col_count] = '\0';
		free(line);
		line = get_next_line(map_fd, 0);
		i++;
	}
	map_copy[i] = NULL;
	free(line);
	line = NULL;
	return (get_next_line(map_fd, 1), map_copy);
}

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
		printf("ICI\n");
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
		return (-1);
	if (!is_valid_top_down_wall(line, &(*map)->col_count))
	{
		free(line);
		return (0);
	}
	printf("line_count :  % d\n", (*map)->line_count);
	while (i <= (*map)->line_count - 1 && line[0] != '\n')
	{
		printf("while line_count :  % d\n", i);
		printf("line : %s\n", line);
		if (!is_valid_middle_wall(line, (*map)->col_count, map))
		{
			printf("ERROR line %d\n", i);
			printf("ERROR line %s\n", line);
			free(line);
			line = NULL;
			return (0);
		}
        if (i == (*map)->line_count - 1)
            if (!is_valid_top_down_wall(line, &(*map)->col_count))
	 	        return (0);
		free(line);
		line = get_next_line(map_fd, 0);
		i++;
	}
	free(line);
	line = NULL;
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

