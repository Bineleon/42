/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:00:34 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 17:31:32 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	int		fd_map;
	t_map	*map;
	char	**map_copy;
	t_data	*game;
	void	*mlx_ptr;

  mlx_ptr = NULL;
	mlx_ptr = mlx_init();
  map = NULL;
  map_copy = NULL;
  game = NULL;
	check_arguments(ac);
	fd_map = open_map_file(av[1]);
	map = allocate_map();
	game = allocate_game(map);
	game->mlx_ptr = mlx_ptr;
	if (!game->mlx_ptr)
		return (EXIT_FAILURE);
	map_copy = validate_and_copy_map(fd_map, map, av[1]);
	if (!map_copy)
	{
		free(map);
		return (EXIT_FAILURE);
	}
	validate_objects(map, map_copy);
	find_size_and_free_map(map_copy);
	map_copy = NULL;
	game->mlx_ptr = mlx_ptr;
	init_textures(game, IMG_SIZE);
	// assign_img_ptr(game);
	init_win(game);
	setup_hooks(game);
	printf("\nICI_main\n");
	mlx_loop(game->mlx_ptr);
  clean(game);
	// clean(game);
	// mlx_destroy_window(mlx_ptr, game.win_ptr);
	// mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	return (0);
}
