/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:00:34 by neleon            #+#    #+#             */
/*   Updated: 2024/07/13 18:27:52 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int handle_key(int key, t_data *game)
// {
//     int x_old = game->map->player_pos_x;
//     int y_old = game->map->player_pos_y;

//     printf("ICI handle_key\n");
//     if (key == KEY_UP && game->map->map[y_old - 1][x_old] != WALL)
//     {
//         if (game->map->map[y_old - 1][x_old] == COLLEC)
//             game->collected += 1;
//         game->map->player_pos_y -= 1; // haut
//         printf("key up\n");
//     }
//     else if (key == KEY_DOWN && game->map->map[y_old + 1][x_old] != WALL)
//     {
//         if (game->map->map[y_old + 1][x_old] == COLLEC)
//             game->collected += 1;
//         game->map->player_pos_y += 1; // bas
//     }
//     else if (key == KEY_LEFT && game->map->map[y_old][x_old - 1] != WALL)
//     {
//         if (game->map->map[y_old][x_old - 1] == COLLEC)
//             game->collected += 1;
//         game->map->player_pos_x -= 1; // gauche
//     }
//     else if (key == KEY_RIGHT && game->map->map[y_old][x_old + 1] != WALL)
//     {
//         if (game->map->map[y_old][x_old + 1] == COLLEC)
//             game->collected += 1;
//         printf("COLLECTED : %d", game->collected);
//         game->map->player_pos_x += 1; // droite
//     }

//     mlx_clear_window(game->mlx_ptr, game->win_ptr);
//     display_new_map(game, x_old, y_old);

//     return (0);
// }

int handle_key_release(int key, t_data *game)
{
    (void)key;
    (void)game;
    return (0);
}

int handle_destroy(t_data *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(0);
    return (0);
}

int	handle_keyrelease(int keysym, t_data *game)
{
    (void) game;
    printf("Keyrelease: %d\n", keysym);
    return (0);
}
void setup_hooks(t_data *game)
{
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_key, game);
    printf("ICI setup_hooks\n");
    mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_key_release, game);
    mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, game);
    mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy, game);
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
	validate_objects(map, map_copy);
  printf("\nICI_main\n");
	init_data(&game, map);
	game.mlx_ptr = mlx_ptr;

	assign_img_ptr(&game);
	init_win(&game);

  setup_hooks(&game);
	mlx_loop(game.mlx_ptr);

	free_resources(map_copy, map, fd_map);
  	free(map);

	return (0);
}
