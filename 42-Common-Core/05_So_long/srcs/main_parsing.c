/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:46 by neleon            #+#    #+#             */
/*   Updated: 2024/07/02 15:59:34 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// int main(int ac, char **av)
// {
//     int fd_map;
//     t_map *map;
//     char **map_copy;
//     int i;

//     i = 0;
//     if (ac != 2)
// 	{
//         ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
//         printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
//         return 1;
//     }

//     fd_map = open(av[1], O_RDONLY);
//     if (fd_map < 0)
// 	{
//         printf("Error opening file");
//         return 1;
//     }

//     map = malloc(sizeof(t_map));
//     if (!map)
// 	{
//         printf("Error allocating memory");
//         close(fd_map);
//         return 1;
//     }
//     map->line_count = 0;
// 	map->col_count = 0;
// 	map->collec	= 0;
// 	map->exit = 0;
// 	map->player = 0;
// 	map_size(av[1], map);
//     map_copy = map_cpy(fd_map, map);
//     if (!map_copy)
// 	{
//         free(map);
//         close(fd_map);
//         return -1;
//     }
//     if (is_valid_format(fd_map, &map) && is_valid_map(fd_map, &map))
//     {
//         find_player_pos(map, map_copy);
//         flood_fill(map_copy, map, map->player_pos.x, map->player_pos.y);
//         printf("\n\n\ncollec : %d\n\n\n", map->ff_collec);
//         printf("\n\n\nexit : %d\n\n\n", map->ff_exit);
//         if (objs_are_reachable(map))
//             printf("Map valid\n");
//         else
//             printf("Unvalid map\n");
//     }
// 	// if(is_valid_format(fd_map, &map))
// 	// {
// 	// 	printf("Map valid\n");
// 		// printf("\n\n\nplayers : %d\n\n\n", map->player);
// 		// printf("\n\n\ncollec : %d\n\n\n", map->collec);
// 		// printf("\n\n\nexit : %d\n\n\n", map->exit);
// 	// }
// 	// else
// 	// 	printf("Unvalid map\n");

//     free_malloc(map_copy, i);
//     free_map(map);
//     close(fd_map);
//     return 0;
// }
