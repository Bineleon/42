/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:53:08 by neleon            #+#    #+#             */
/*   Updated: 2024/07/17 15:06:05 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_data *game, int img_size)
{
	int	i;

	i = 0;
	check_fail_texture(game, i++, FLOOR_PATH, img_size);
	check_fail_texture(game, i++, WALL_PATH, img_size);
	check_fail_texture(game, i++, COLLEC_PATH, img_size);
	check_fail_texture(game, i++, CHAR_L_PATH, img_size);
	check_fail_texture(game, i++, CHAR_R_PATH, img_size);
	check_fail_texture(game, i++, EXIT_PATH, img_size);
	game->current_img_char = game->textures[4];
	init_alpha(game, IMG_SIZE);
	init_num(game, IMG_SIZE);
}

int	check_fail_texture(t_data *game, int i, char *path, int img_size)
{
	game->textures[i] = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_size,
			&img_size);
	if (!game->textures[i])
		return (clean_textures(game), 0);
	return (1);
}
