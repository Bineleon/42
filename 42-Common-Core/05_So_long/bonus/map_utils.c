/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:09:05 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 18:57:26 by neleon           ###   ########.fr       */
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

int	open_map_file(char *av, t_data *game)
{
	int	map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		clean(game);
	}
	return (map_fd);
}

char	*read_first_line(int map_fd, t_data *game)
{
	char	*line;

	line = get_next_line(map_fd, 0);
	if (!line)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		exit(EXIT_FAILURE);
	}
	if (line[0] != WALL)
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		if (game)
			clean(game);
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

