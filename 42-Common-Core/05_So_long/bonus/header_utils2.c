/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:35:18 by neleon            #+#    #+#             */
/*   Updated: 2024/07/19 19:49:25 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	*get_alpha_image(t_data *game, char c)
{
	if (c == 'S')
		return (game->alpha[0]);
	else if (c == 't')
		return (game->alpha[1]);
	else if (c == 'e')
		return (game->alpha[2]);
	else if (c == 'p')
		return (game->alpha[3]);
	else if (c == 'C')
		return (game->alpha[5]);
	else if (c == 'o')
		return (game->alpha[6]);
	else if (c == 'u')
		return (game->alpha[7]);
	else if (c == 'n')
		return (game->alpha[8]);
	else if (c == 's')
		return (game->alpha[9]);
	else
		return (NULL);
}

void	*get_special_image(t_data *game, char c)
{
	if (c == ':')
		return (game->alpha[4]);
	else if (c == '/')
		return (game->alpha[10]);
	else if (c == ' ')
		return (game->textures[0]);
	else
		return (NULL);
}

void	display_digits(t_data *game, char c, int *x)
{
	void	*img;

	img = game->num[c - '0'];
	if (img)
		img_to_win(game, img, (*x * IMG_SIZE), 0);
	*x += 1;
}
