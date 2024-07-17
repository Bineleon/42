/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:32:00 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/17 16:48:19 by bineleon         ###   ########.fr       */
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
	// mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	// free(game->mlx_ptr);
  clean(game);
	exit(0);
	return (0);
}

// int on_destroy(t_data *game)
// {
// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	mlx_destroy_display(game->mlx_ptr);
// 	free(game->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int	handle_keyrelease(int keysym, t_data *game)
// {
//     (void) game;
//     printf("Keyrelease: %d\n", keysym);
//     return (0);
// }
void	setup_hooks(t_data *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_key, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease,
		game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy,
		game);
}
