/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:00:34 by neleon            #+#    #+#             */
/*   Updated: 2024/07/13 15:44:02 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main(int ac, char **av)
// {
//     int fd_map;
//     t_map *map;
//     char **map_copy;
//     // void *mlx_ptr;

//     // mlx_ptr = init_graphics();
//     check_arguments(ac);
//     fd_map = open_map_file(av[1]);
//     map = allocate_map();
//     map_copy = validate_and_copy_map(fd_map, map, av[1]);
//     validate_objects(map, map_copy);
//     free_resources(map_copy, map, fd_map);
//     return (0);
// }

int handle_key(int key, void *param)
{
    (void)param;
    printf("Key pressed: %d\n", key);
    return (0);
}

int main(int ac, char **av)
{
	int fd_map;
	t_map *map;
	char **map_copy;
	t_data game;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	game.mlx_ptr = mlx_ptr;
	if (!game.mlx_ptr)
		return (EXIT_FAILURE);

	check_arguments(ac);

	fd_map = open_map_file(av[1]);

	map = allocate_map();
	map_copy = validate_and_copy_map(fd_map, map, av[1]);
	if (!map_copy)
	{
		free(map);
		return (EXIT_FAILURE);
	}
  printf("\nICI\n");
	validate_objects(map, map_copy);
	init_data(&game, map);
	game.mlx_ptr = mlx_ptr;

	assign_img_ptr(&game);
	init_win(&game);

  mlx_key_hook(game.win_ptr, handle_key, NULL);
	mlx_loop(game.mlx_ptr);

	free_resources(map_copy, map, fd_map);
  	free(map);

	return (0);
}
