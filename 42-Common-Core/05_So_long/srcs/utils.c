/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:08 by neleon            #+#    #+#             */
/*   Updated: 2024/07/15 16:37:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// void	ft_mapnew(t_map *map)
// {
// 	map = malloc(1 * sizeof(t_map ));
// 	if (!map)
// 		return ;
// 	map->line_count = 0;
// 	map->col_count = 0;
// 	map->collec	= 0;
// 	map->exit = 0;
// 	map->player = 0;
// 	map->ff_collec	= 0;
// 	map->ff_exit = 0;
// }

void	free_map(t_map *map)
{
	map->collec = 0;
	map->exit = 0;
	map->player = 0;
	map->line_count = 0;
	map->col_count = 0;
	map->ff_collec = 0;
	map->ff_exit = 0;
	free(map);
	map = NULL;
}

void	check_empty_line(char *line, int map_fd)
{
	free_line(line);
	get_next_line(map_fd, 1);
	close(map_fd);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
}

int	clean(t_data *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		free_resources(game->map->map, game->map);
		// free(game->map->map);
		free_map(game->map);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_collec);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_exit);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_char_left);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_char_right);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_wall);
		mlx_destroy_image(game->mlx_ptr, game->ptr_img_floor);
		mlx_destroy_image(game->mlx_ptr, game->current_img_char);
		mlx_destroy_image(game->mlx_ptr, game->img_curr_display);
	}
	if(game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}


void	init_data(t_data *game, t_map *map)
{
	// game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	game->ptr_img_collec = NULL;
	game->ptr_img_exit = NULL;
	game->ptr_img_char_left = NULL;
	game->ptr_img_char_right = NULL;
	game->ptr_img_wall = NULL;
	game->ptr_img_floor = NULL;
	game->current_img_char = NULL;
	game->img_curr_display = NULL;
	game->collected = 0;
	game->player_steps = 0;
	game->map = map;
}