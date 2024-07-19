/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:11:33 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/19 19:53:45 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_header(t_data *game)
{
	int	x;

	x = 0;
	display_text(game, &x, "Steps:");
	display_count(game, &x, game->player_steps);
	display_text(game, &x, " Count:");
	display_count(game, &x, game->collected);
	display_char(game, '/', &x);
	display_count(game, &x, game->map->collec);
	while (x < game->map->col_count)
	{
		img_to_win(game, game->textures[0], x * IMG_SIZE, 0);
		x++;
	}
}

void	display_char(t_data *game, char c, int *x)
{
	void	*img;

	if (c >= '0' && c <= '9')
	{
		display_digits(game, c, x);
	}
	else
	{
		img = get_alpha_image(game, c);
		if (!img)
			img = get_special_image(game, c);
		if (img)
			img_to_win(game, img, (*x * IMG_SIZE), 0);
		*x += 1;
	}
}

void	display_text(t_data *game, int *x, char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		display_char(game, text[i], x);
		i++;
	}
}

void	display_count(t_data *game, int *x, int count)
{
	char	*count_str;
	int		i;

	i = 0;
	count_str = ft_itoa(count);
	while (count_str[i])
	{
		display_digits(game, count_str[i], x);
		i++;
	}
	free(count_str);
}
