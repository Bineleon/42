/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:25:01 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 19:20:38 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

short	check_map_limit_size(t_map *map)
{
	if (map->col_count < 18)
	{
		ft_putstr_fd("Sorry but this map is too small 🤏,", 2);
		ft_putstr_fd(" try with a bigger one!\n", 2);
		return (0);
	}
	else if (map->col_count > 51)
	{
		ft_putstr_fd("Sorry but this map is too big 🥵,", 2);
		ft_putstr_fd(" try with a smaller one!\n", 2);
		return (0);
	}
	return (1);
}

short	is_valid_obj_count(t_map *map)
{
	if (map->player != 1 || map->exit != 1)
	{
		ft_putstr_fd("Unvalid map: wrong player or exit count\n", 2);
		return (0);
	}
	if (map->collec < 1)
	{
		ft_putstr_fd("Unvalid map: map need at least 1 collectible\n", 2);		
		return (0);
	}
	return (1);
}

short	is_valid_map(int map_fd, t_map **map)
{
	if (!is_valid_format(map_fd, map) || !is_valid_obj_count(*map))
		return (0);
	return (1);
}

void	object_count(char square, int *collec, int *exit)
{
	if (square == COLLEC)
		(*collec)++;
	else if (square == EXIT)
		(*exit)++;
	else
		return ;
}

short	objs_are_reachable(t_map *map)
{
	if (map->ff_collec != map->collec || map->ff_exit != 1)
	{
		ft_putstr_fd("Unvalid map : unreachable collectible(s) or exit \n", 2);
		return (0);
	}
	return (1);
}
