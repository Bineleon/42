/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:09:05 by neleon            #+#    #+#             */
/*   Updated: 2024/07/02 18:10:07 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (!line || line[0] == '\n')
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		return ;
	}
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
		printf("%s\n", line);
		map_copy[i] = ft_strdup(line);
		map_copy[i][map->col_count] = '\0';
		free(line);
		line = get_next_line(map_fd, 0);
		i++;
	}
	map_copy[i] = NULL;
	if (line)
		free_line(line);
	get_next_line(map_fd, 1);
	return (close(map_fd), map_copy);
}