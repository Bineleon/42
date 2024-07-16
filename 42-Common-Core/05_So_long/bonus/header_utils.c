/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:11:33 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/16 15:49:46 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void display_header(t_data *game)
{
    int x;
    x = 0;
    display_text(game, &x, "Steps:");
    display_count(game, &x, game->player_steps);
    display_text(game, &x, " Count:");
    display_count(game, &x, game->collected);
    display_char(game, '/', &x, IMG_SIZE);
    display_count(game, &x, game->map->collec);
    printf("\nx = %d\n", x);
    while (x < game->map->col_count)
    {
        img_to_win(game, game->ptr_img_floor, x * IMG_SIZE, 0);
        x++;
    }
}

void display_char(t_data *game, char c, int *x, int img_size)
{
    void *img;

    img = NULL;
    if (c == 'S')
    {
        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_S, &img_size, &img_size);
        game->ptr_ltr_s = img;
    }
    else if (c == 't')
    {
        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_T, &img_size, &img_size);
        game->ptr_img_ltr_t = img;
    }
    else if (c == 'e')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_E, &img_size, &img_size);
    }
    else if (c == 'p')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_P, &img_size, &img_size);
    }
    else if (c == ':')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_DOUBLE_P, &img_size, &img_size);
    }
    else if (c == 'C')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_C, &img_size, &img_size);
    }
    else if (c == 'u')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_U, &img_size, &img_size);
    }
    else if (c == 'n')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_N, &img_size, &img_size);
    }
    else if (c == 'o')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_O, &img_size, &img_size);
    }
    else if (c == 's')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_S_MIN, &img_size, &img_size);
    }
    else if (c == '/')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, LR_SLASH, &img_size, &img_size);
    }
    else if (c == ' ')
    {

        img = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_PATH, &img_size, &img_size);
    }
    else if (c >= '0' && c <= '9')
        display_digits(game, c, x, img_size);
    if (img)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, (*x * IMG_SIZE), 0);
    *x += 1;
    game->img_curr_display = img;
}


void display_text(t_data *game, int *x, char *text)
{
    int i;

    i = 0;
    int img_size = IMG_SIZE;
    while (text[i])
    {
        display_char(game, text[i], x, img_size);
        i++;
    }
}


void display_count(t_data *game, int *x, int count)
{
    char *count_str;
    int i;

    i = 0;
    count_str = ft_itoa(count);
    while (count_str[i])
    {
        display_digits(game, count_str[i], x, IMG_SIZE);
        i++;
    }
    free(count_str);
}

void display_digits(t_data *game, char c, int *x, int img_size)
{
    void *img;
    char *path;

    img = NULL;
    path = digit_path(c);
    if (path)
        img = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_size, &img_size);
    if (img)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, (*x * IMG_SIZE), 0);
    *x += 1;
    game->img_curr_display = img;
}


char *digit_path(char c)
{
    char *digits[10];

    digits[0] = D_0;
    digits[1] = D_1;
    digits[2] = D_2;
    digits[3] = D_3;
    digits[4] = D_4;
    digits[5] = D_5;
    digits[6] = D_6;
    digits[7] = D_7;
    digits[8] = D_8;
    digits[9] = D_9;

    if (c >= '0' && c <= '9')
        return (digits[c - '0']);
    return NULL;
}
