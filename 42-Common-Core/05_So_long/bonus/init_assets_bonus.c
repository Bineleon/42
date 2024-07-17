/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:55:44 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 02:25:25 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_alpha(t_data *game, int img_size)
{
	game->alpha[0] = mlx_xpm_file_to_image(game->mlx_ptr, LR_S, &img_size,
			&img_size);
	game->alpha[1] = mlx_xpm_file_to_image(game->mlx_ptr, LR_T, &img_size,
			&img_size);
	game->alpha[2] = mlx_xpm_file_to_image(game->mlx_ptr, LR_E, &img_size,
			&img_size);
	game->alpha[3] = mlx_xpm_file_to_image(game->mlx_ptr, LR_P, &img_size,
			&img_size);
	game->alpha[4] = mlx_xpm_file_to_image(game->mlx_ptr, LR_DOUBLE_P,
			&img_size, &img_size);
	game->alpha[5] = mlx_xpm_file_to_image(game->mlx_ptr, LR_C, &img_size,
			&img_size);
	game->alpha[6] = mlx_xpm_file_to_image(game->mlx_ptr, LR_O, &img_size,
			&img_size);
	game->alpha[7] = mlx_xpm_file_to_image(game->mlx_ptr, LR_U, &img_size,
			&img_size);
	game->alpha[8] = mlx_xpm_file_to_image(game->mlx_ptr, LR_N, &img_size,
			&img_size);
	game->alpha[9] = mlx_xpm_file_to_image(game->mlx_ptr, LR_S_MIN, &img_size,
			&img_size);
	game->alpha[10] = mlx_xpm_file_to_image(game->mlx_ptr, LR_SLASH, &img_size,
			&img_size);
}

void	init_num(t_data *game, int img_size)
{
	game->num[0] = mlx_xpm_file_to_image(game->mlx_ptr, D_0, &img_size,
			&img_size);
	game->num[1] = mlx_xpm_file_to_image(game->mlx_ptr, D_1, &img_size,
			&img_size);
	game->num[2] = mlx_xpm_file_to_image(game->mlx_ptr, D_2, &img_size,
			&img_size);
	game->num[3] = mlx_xpm_file_to_image(game->mlx_ptr, D_3, &img_size,
			&img_size);
	game->num[4] = mlx_xpm_file_to_image(game->mlx_ptr, D_4, &img_size,
			&img_size);
	game->num[5] = mlx_xpm_file_to_image(game->mlx_ptr, D_5, &img_size,
			&img_size);
	game->num[6] = mlx_xpm_file_to_image(game->mlx_ptr, D_6, &img_size,
			&img_size);
	game->num[7] = mlx_xpm_file_to_image(game->mlx_ptr, D_7, &img_size,
			&img_size);
	game->num[8] = mlx_xpm_file_to_image(game->mlx_ptr, D_8, &img_size,
			&img_size);
	game->num[9] = mlx_xpm_file_to_image(game->mlx_ptr, D_9, &img_size,
			&img_size);
}
