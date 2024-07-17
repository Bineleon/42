/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:02:29 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/17 16:14:35 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*init_graphics(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		ft_putstr_fd("Error initializing graphics", 2);
		exit(EXIT_FAILURE);
	}
	return (mlx_ptr);
}

void	check_arguments(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
		ft_printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
		exit(EXIT_FAILURE);
	}
}

t_map	*allocate_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error allocating memory", 2);
		exit(EXIT_FAILURE);
	}
	init_map(map);
	return (map);
}

char	**validate_and_copy_map(int fd_map, t_map *map, char *filename)
{
	char	**map_copy;

	map_size(filename, map);
	if (is_valid_map(fd_map, &map))
		printf("Map valid\n");
	fd_map = open(filename, O_RDONLY);
	map_copy = map_cpy(fd_map, map);
	if (!map_copy)
	{
		close(fd_map);
		exit(EXIT_FAILURE);
	}
	if (!is_valid_format(fd_map, &map) || !is_valid_map(fd_map, &map))
  {
    ft_putstr_fd("Wrong map\n", 2);
		exit(EXIT_FAILURE);
  }
	return (map_copy);
}

void	validate_objects(t_map *map, char **map_copy)
{
	printf("\nICI_valiate_object\n");
	find_player_pos(map, map_copy);
	flood_fill(map_copy, map, map->player_pos_x, map->player_pos_y);
	printf("\n\n\ncollec : %d\n\n\n", map->ff_collec);
	printf("\n\n\nexit : %d\n\n\n", map->ff_exit);
	if (!objs_are_reachable(map))
  {
    // free_resources(map);
		exit(EXIT_FAILURE);
  }
}

void	free_resources(t_map *map)
{
	int	i;

	i = 0;

	while (map->map[i])
		i++;
	free_malloc(map->map, i);
}

void	find_size_and_free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	free_malloc(map, i);
}
