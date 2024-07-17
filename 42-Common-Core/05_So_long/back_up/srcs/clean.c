/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:14:28 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 20:29:05 by neleon           ###   ########.fr       */
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


void	free_line(char *line)
{
  if (line)
  {
	  free(line);
	  line = NULL;
  }
}


void	clean_textures(t_data *game)
{
	int i;

	i = 0;
	while(i < 6 && game->textures[i])
	{
		mlx_destroy_image(game->mlx_ptr, game->textures[i]);
		i++;
	}
}

void	clean_alpha(t_data *game)
{
	int i;

	i = 0;
	while(i < 11 && game->alpha[i])
	{
		mlx_destroy_image(game->mlx_ptr, game->alpha[i]);
		i++;
	}
}

void	clean_num(t_data *game)
{
	int i;

	i = 0;
	while(i < 10 && game->num[i])
	{
		mlx_destroy_image(game->mlx_ptr, game->num[i]);
		i++;
	}
}

void	clean_assets(t_data *game)
{
	clean_textures(game);
	clean_alpha(game);
	clean_num(game);
}

void	clean(t_data *game)
{
	if (game->map)
	{
		free_resources(game->map);
		free_map(game->map);
		clean_assets(game);
	}
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}
