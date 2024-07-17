/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:55:44 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 17:37:49 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	init_alpha(t_data *game, int img_size)
{
  int i;

  i = 0;
	init_and_check_fail_alpha(game, i++, LR_S, img_size);
	init_and_check_fail_alpha(game, i++, LR_T, img_size);
	init_and_check_fail_alpha(game, i++, LR_E, img_size);
	init_and_check_fail_alpha(game, i++, LR_P, img_size);
	init_and_check_fail_alpha(game, i++, LR_DOUBLE_P, img_size);
	init_and_check_fail_alpha(game, i++, LR_C, img_size);
	init_and_check_fail_alpha(game, i++, LR_O, img_size);
	init_and_check_fail_alpha(game, i++, LR_U, img_size);
	init_and_check_fail_alpha(game, i++, LR_N, img_size);
	init_and_check_fail_alpha(game, i++, LR_S_MIN, img_size);
	init_and_check_fail_alpha(game, i++,  LR_SLASH, img_size);
}

void	init_num(t_data *game, int img_size)
{
  int i;

  i = 0;
	init_and_check_fail_num(game, i++, D_0, img_size);
	init_and_check_fail_num(game, i++, D_1, img_size);
	init_and_check_fail_num(game, i++, D_2, img_size);
	init_and_check_fail_num(game, i++, D_3, img_size);
	init_and_check_fail_num(game, i++, D_4, img_size);
	init_and_check_fail_num(game, i++, D_5, img_size);
	init_and_check_fail_num(game, i++, D_6, img_size);
	init_and_check_fail_num(game, i++, D_7, img_size);
	init_and_check_fail_num(game, i++, D_8, img_size);
	init_and_check_fail_num(game, i++, D_9, img_size);
}

int	init_and_check_fail_alpha(t_data *game, int i, char *path, int img_size)
{
	game->alpha[i] = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_size, &img_size);
	if (!game->alpha[i])
		return (clean_alpha(game), 0);
	return (1);
}

int	init_and_check_fail_num(t_data *game, int i, char *path, int img_size)
{
	game->num[i] = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_size,
			&img_size);
	if (!game->num[i])
		return (clean_alpha(game), 0);
	return (1);
}
