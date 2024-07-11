/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:00:34 by neleon            #+#    #+#             */
/*   Updated: 2024/07/11 20:08:39 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int ac, char **av)
{
    int fd_map;
    t_map *map;
    char **map_copy;
    // void *mlx_ptr;

    // mlx_ptr = init_graphics();
    check_arguments(ac);
    fd_map = open_map_file(av[1]);
    map = allocate_map();
    map_copy = validate_and_copy_map(fd_map, map, av[1]);
    validate_objects(map, map_copy);
    free_resources(map_copy, map, fd_map);
    return (0);
}
