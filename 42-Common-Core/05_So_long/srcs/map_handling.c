/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:12 by neleon            #+#    #+#             */
/*   Updated: 2024/07/18 19:36:21 by neleon           ###   ########.fr       */
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