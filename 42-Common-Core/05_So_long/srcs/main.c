/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:53:10 by neleon            #+#    #+#             */
/*   Updated: 2024/07/01 15:23:48 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main(int ac, char **av)
// {
//     int fd_map;
//     t_map *map;
//     // char **map_copy;
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
// 	if(is_valid_format(fd_map, &map))
// 	{
// 		printf("Map valid\n");
// 		printf("\n\n\nplayers : %d\n\n\n", map->player);
// 		printf("\n\n\ncollec : %d\n\n\n", map->collec);
// 		printf("\n\n\nexit : %d\n\n\n", map->exit);
// 	}
// 	else
// 		printf("Unvalid map\n");

//     // map_copy = map_cpy(fd_map, map);
//     // if (!map_copy)
// 	// {
//     //     free(map);
//     //     close(fd_map);
//     //     return -1;
//     // }

//     // while (map_copy[i]) {
//     //     printf("%s\n", map_copy[i]);
//     //     i++;
//     // }
//     // free_malloc(map_copy, i);
//     free_map(map);
//     close(fd_map);
//     return 0;
// }


// int	main(int ac, char **av)
// {
// 	int		fd_map;
// 	// int		line;
// 	// int		col;
// 	t_map	*map;
// 	char	**map_copy;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	fd_map = open(av[1], O_RDONLY);
// 	map = malloc(sizeof(t_map *));
// 	if (ac != 2)
// 	{
// 		ft_putstr_fd("\033[1;35mHep hep hep!!\033[0m", 2);
// 		ft_printf("\033[1;35m You need to put 1 args, not %d\n\033[0m", ac - 1);
// 	}
// 	else if (ac == 2)
// 	{
// 		// map_size(fd_map, &map);
// 		map_copy = map_cpy(fd_map, map);
// 		if (!map_copy)
// 		{
// 			printf("COUCOU\n");
// 			free(map_copy);
// 			return (-1);
// 		}
// 		while (map_copy[i])
// 		{
// 			printf("%s\n", map_copy[i]);
// 			i++;
// 		}
// 		free_malloc(map_copy, i);
// 	}
// 	free_map(map);
// 	close(fd_map);
// 	return (0);
// }
