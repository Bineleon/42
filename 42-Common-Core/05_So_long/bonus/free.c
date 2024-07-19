/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:24 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 19:07:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	map->collec = 0;
	map->exit = 0;
	map->player = 0;
	map->line_count = 0;
	map->col_count = 0;
	map->ff_collec = 0;
	map->ff_exit = 0;
	map->player_pos_x = 0;
	map->player_pos_y = 0;
	map->exit_pos_x = 0;
	map->exit_pos_y = 0;
	free(map);
	map = NULL;
}

void	free_game(t_data *game)
{
	game->current_img_char = NULL;
	game->collected = 0;
	game->player_steps = 0;
	free(game);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
}

void	find_size_and_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	free_malloc(map, i);
}