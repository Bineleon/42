/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:34:59 by neleon            #+#    #+#             */
/*   Updated: 2024/06/26 00:33:59 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		get_map_fd(char *map_file)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

char	*check_line(char *line)
{
	
	while(*line)
	{
		if(*line == )
	}
}

int		is_valid_map(int map_fd, t_map *map)
{
	char	*line;
	
	line = malloc(1);
	
	while (line)
	{
		free(line);
		line = get_next_line(map_fd, 0);

	}
}

char	**map_cpy(int map_fd)
{
	int		map_fd;
	

	
	
}