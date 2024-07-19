/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:18 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 18:17:02 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_map(t_map *map)
{
	map->line_count = 0;
	map->col_count = 0;
	map->player = 0;
	map->collec = 0;
	map->exit = 0;
	map->ff_collec = 0;
	map->ff_exit = 0;
	map->player_pos_y = 0;
	map->player_pos_x = 0;
	map->exit_pos_y = 0;
	map->exit_pos_x = 0;
	map->map = NULL;
}

t_map	*allocate_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error allocating memory", 2);
		exit(EXIT_FAILURE);
	}
	init_map(map);
	return (map);
}