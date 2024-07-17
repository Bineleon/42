/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:08 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 17:12:52 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_empty_line(char *line, int map_fd)
{
	free_line(line);
	get_next_line(map_fd, 1);
	close(map_fd);
}

void	init_data(t_data *game, t_map *map)
{
	game->mlx_ptr = NULL;
  game->win_ptr = NULL;
	game->current_img_char = NULL;
	game->collected = 0;
	game->player_steps = 0;
	game->map = map;
}
