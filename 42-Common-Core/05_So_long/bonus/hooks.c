/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:32:00 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/18 01:34:49 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keyrelease(int key, t_data *game)
{
	(void)key;
	(void)game;
	return (0);
}

int	handle_destroy(t_data *game)
{
	clean(game);
	return (0);
}

void	setup_hooks(t_data *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_key, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease,
		game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy,
		game);
}
