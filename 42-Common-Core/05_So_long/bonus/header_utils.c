/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:11:33 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/16 21:43:46 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	printf("\nx = %d\n", x);
	while (x < game->map->col_count)
	{
		img_to_win(game, game->textures[0], x * IMG_SIZE, 0);
		x++;
	}
}

void	display_char(t_data *game, char c, int *x)
{
	void	*img;

	img = NULL;
	if (c == 'S')
		img = game->alpha[0];
	else if (c == 't')
		img = game->alpha[1];
	else if (c == 'e')
		img = game->alpha[2];
	else if (c == 'p')
		img = game->alpha[3];
	else if (c == ':')
		img = game->alpha[4];
	else if (c == 'C')
		img = game->alpha[5];
	else if (c == 'o')
		img = game->alpha[6];
	else if (c == 'u')
		img = game->alpha[7];
	else if (c == 'n')
		img = game->alpha[8];
	else if (c == 's')
		img = game->alpha[9];
	else if (c == '/')
		img = game->alpha[10];
	else if (c == ' ')
		img = game->textures[0];
	else if (c >= '0' && c <= '9')
		display_digits(game, c, x);
	if (img)
		img_to_win(game, img, (*x * IMG_SIZE), 0);
	*x += 1;
}

void	display_text(t_data *game, int *x, char *text)
{
	int	i;
	int	img_size;

	i = 0;
	img_size = IMG_SIZE;
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

void	display_digits(t_data *game, char c, int *x)
{
	void	*img;

	img = game->num[c - '0'];
	if (img)
		img_to_win(game, img, (*x * IMG_SIZE), 0);
	*x += 1;
}
