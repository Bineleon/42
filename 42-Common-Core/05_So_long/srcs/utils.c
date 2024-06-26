/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:08 by neleon            #+#    #+#             */
/*   Updated: 2024/07/02 17:06:53 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_mapnew(t_map *map)
{
	map = malloc(1 * sizeof(t_map ));
	if (!map)
		return ;
	map->line_count = 0;
	map->col_count = 0;
	map->collec	= 0;
	map->exit = 0;
	map->player = 0;
}

void	free_map(t_map *map)
{
	map->collec = 0;
	map->exit = 0;
	map->player = 0;
	map->line_count = 0;
	map->col_count = 0;
	free(map);
}

void	check_empty_line(char *line, int map_fd)
{
	free_line(line);
	get_next_line(map_fd, 1);
	close(map_fd);
}

void    free_line(char *line)
{
    free(line);
	line = NULL;
}
