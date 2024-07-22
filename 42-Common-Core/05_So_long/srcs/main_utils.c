/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:02:29 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/22 22:38:19 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

short	check_filename_extention(char *av, char *extention)
{
	size_t	len;
	size_t	len_ext;
	int		cmp;

	len = ft_strlen(av);
	len_ext = ft_strlen(extention);
	if (len == len_ext)
		return (0);
	cmp = ft_strncmp(av + (len - len_ext), extention, len_ext);
	if (cmp != 0)
		return (0);
	return (1);
}

void	check_arguments(int ac, char *av, void *mlx_ptr)
{
	if (ac != 2)
	{
		ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
		ft_printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
		exit(EXIT_FAILURE);
	}
	if (!check_filename_extention(av, ".ber"))
	{
		ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
		ft_putstr_fd("\033[1;35m The map file should have a name\033[0m", 2);
		ft_putstr_fd("\033[1;35m and a \".ber\" extention, \033[0m", 2);
		ft_putstr_fd("\033[1;35mnot whatever 💩 you gave me !\n\033[0m", 2);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

void	validate_and_copy_map(t_data *game, int fd_map, t_map *map,
		char *filename)
{
	map_size(filename, map, game);
	if (!is_valid_map(fd_map, &map, game))
		clean(game);
	else
	{
		fd_map = open(filename, O_RDONLY);
		if (fd_map < 0)
			clean(game);
		map_cpy(fd_map, map, game);
		if (!game->map_copy)
		{
			close(fd_map);
			clean(game);
		}
	}
}

void	validate_objects(t_map *map, char **map_copy, t_data *game)
{
	find_player_pos(map, map_copy);
	flood_fill(map_copy, map, map->player_pos_x, map->player_pos_y);
	if (!objs_are_reachable(map))
		clean(game);
}
