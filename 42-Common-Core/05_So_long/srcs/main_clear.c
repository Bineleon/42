/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:00:34 by neleon            #+#    #+#             */
/*   Updated: 2024/07/18 19:25:14 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	int		fd_map;
	t_map	*map;
	// char	**game->map_copy;
	t_data	*game;
	void	*mlx_ptr;

	mlx_ptr = NULL;
	mlx_ptr = mlx_init();
	check_arguments(ac);
	map = allocate_map();
	game = allocate_game(map);
	game->mlx_ptr = mlx_ptr;
	if (!game->mlx_ptr)
		clean(game);
	fd_map = open_map_file(av[1]);
	validate_and_copy_map(game, fd_map, map, av[1]);
	printf("ICI main\n\n");
	if (!game->map_copy)
		return (EXIT_FAILURE);
	validate_objects(map, game->map_copy);
	find_size_and_free_map(game->map_copy);
	game->map_copy = NULL;
	init_textures(game, IMG_SIZE);
	init_win(game);
	setup_hooks(game);
	mlx_loop(game->mlx_ptr);
	clean(game);
	return (0);
}
