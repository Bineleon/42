/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:46 by neleon            #+#    #+#             */
/*   Updated: 2024/07/15 17:32:35 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int on_destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./assets/exit.xpm";
// 	int		img_width;
// 	int		img_height;
// 	t_data data;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (1);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 1400, 1200, "So_long baby");
// 	if (!data.win_ptr)
// 		return (free(data.mlx_ptr), 1);
// 	mlx_put_image_to_window(mlx, data.win_ptr, img, 75, 0);
// 	// Register key release hook
// 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

// 	// Register destroy hook
// 	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

// 	// Loop over the MLX pointer
// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }



// int main(void)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "So_long baby");
// 	if (!win_ptr)
// 		return (free(mlx_ptr), 1);
// 	mlx_loop(mlx_ptr);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// 	return (0);
// }
