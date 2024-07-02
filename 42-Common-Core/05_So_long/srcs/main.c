/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:53:10 by neleon            #+#    #+#             */
/*   Updated: 2024/07/02 18:20:27 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main(int ac, char **av)
// {
//     int fd_map;
//     t_map *map;
//     char **map_copy;
//     int i;
// 	void *mlx_ptr;
 
//     i = 0;
// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
//     if (ac != 2)
// 	{
//         ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
//         printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
//         return (1);
//     }
// 	fd_map = open(av[1], O_RDONLY);
//     if (fd_map < 0)
// 	{
//         ft_putstr_fd("Error opening file", 2);
// 		close(fd_map);
//         return 1;
//     }
//     map = malloc(sizeof(t_map));
//     if (!map)
// 	{
//         ft_putstr_fd("Error allocating memory", 2);
//         close(fd_map);
//         return (1);
//     }
//  map->line_count = 0;
// 	map->col_count = 0;
// 	map->collec	= 0;
// 	map->exit = 0;
// 	map->player = 0;
// 	map->ff_collec	= 0;
// 	map->ff_exit = 0;
// 	map_size(av[1], map);
// 	if(is_valid_map(fd_map, &map))
// 	{
// 		printf("Map valid\n");
// 	}
// 	fd_map = open(av[1], O_RDONLY);
// 	map_copy = map_cpy(fd_map, map);
//     if (!map_copy)
// 	{
//         close(fd_map);
//         return -1;
//     }
// 	if (is_valid_format(fd_map, &map) && is_valid_map(fd_map, &map))
//     {
//         find_player_pos(map, map_copy);
//         flood_fill(map_copy, map, map->player_pos.x, map->player_pos.y);
//         printf("\n\n\ncollec : %d\n\n\n", map->ff_collec);
//         printf("\n\n\nexit : %d\n\n\n", map->ff_exit);
//         if (objs_are_reachable(map))
//             printf("Map valid : objs are reachable\n");
//         else
//             printf("Unvalid map\n");
//     }
// 	else
// 		exit(EXIT_FAILURE);

//     while (map_copy[i])
//         i++;
//     free_malloc(map_copy, i);
//     free_map(map);
//     close(fd_map);
//     return 0;
// }
