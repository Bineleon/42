/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:09:05 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 22:11:51 by neleon           ###   ########.fr       */
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
		ft_printf(RED);
		ft_putstr_fd("Error opening file\n", 2);
		ft_printf(RESET);
		clean(game);
	}
	return (map_fd);
}

char	*read_first_line(int map_fd, t_data *game)
{
	char	*line;

	line = get_next_line(map_fd, 0);
	if (!line || !line[0])
	{
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		clean(game);
	}
	if (line[0] != WALL)
	{
		ft_printf(RED);
		ft_putstr_fd("Unvalid map format :", 2);
		ft_putstr_fd(" the map should be surrounded by walls.\n", 2);
		ft_printf(RESET);
		free_line(line);
		get_next_line(map_fd, 1);
		close(map_fd);
		if (game)
			clean(game);
	}
	return (line);
}

void	validate_first_line(char *line, int map_fd, t_data *game)
{
	if (!line || !line[0])
	{
		ft_printf(RED);
		ft_putstr_fd("Invalid map file\n", 2);
		ft_printf(RESET);
		clean_map_reading(line, map_fd);
		if (game)
			clean(game);
	}
}
