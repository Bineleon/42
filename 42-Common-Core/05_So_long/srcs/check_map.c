/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/06/26 12:59:33 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_fd(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

int is_valid_wall_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL)
            return (0);
        i++;
	}
    return (1);
}

int	is_valid_map(int map_fd, t_map *map)
{
	char	*line;
    (void) map;
	line = get_next_line(map_fd, 0);
    return(is_valid_wall_line(line));
	// while (line)
	// {
	// 	free(line);
	// }
}

// char	**map_cpy(int map_fd)
// {
// 	int	map_fd;
// }
