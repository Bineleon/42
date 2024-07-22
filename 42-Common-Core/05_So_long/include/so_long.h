/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:28:06 by neleon            #+#    #+#             */
/*   Updated: 2024/07/22 20:22:47 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/srcs/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "../mlx/mlx.h"
# include "./constants.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

/////////////////  Structures  /////////////////

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	int		line_count;
	int		col_count;
	int		player;
	int		collec;
	int		exit;
	int		ff_collec;
	int		ff_exit;
	int		player_pos_y;
	int		player_pos_x;
	int		exit_pos_y;
	int		exit_pos_x;
	char	**map;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[7];
	void	*alpha[11];
	void	*num[10];
	void	*current_img_char;
	int		collected;
	int		player_steps;
	char	**map_copy;
	t_map	*map;
}			t_data;

///////////////// Check_map /////////////////

void		map_cpy(int map_fd, t_map *map, t_data *game);
short		is_valid_map(int map_fd, t_map **map, t_data *game);
int			is_valid_top_down_wall(char *line, int *col_count);
int			is_valid_middle_wall(char *line, int col_count, t_map **map);
int			is_valid_format(int map_fd, t_map **map, t_data *game);
short		is_valid_obj_count(t_map *map);

short		check_map_limit_size(t_map *map);
char		*read_first_line(int map_fd, t_data *game);
char		*read_first_line_map(int map_fd, t_data *game);
int			open_map_file(char *av, t_data *game);
void		validate_first_line(char *line, int map_fd, t_data *game);
void		calculate_map_size(t_data *game, t_map *map, int map_fd,
				char *line);
void		clean_map_reading(char *line, int map_fd);
void		map_size(char *av, t_map *map, t_data *game);
int			map_len(char *line);
void		object_count(char square, int *collec, int *exit);
// void		init_map(t_map *map);

/////////////////  Utils   /////////////////

void		free_map(t_map *map);
void		free_line(char *line);
// void		check_empty_line(char *line, int map_fd);
t_data		*allocate_game(t_map *map);
void		init_data(t_data *game, t_map *map);

/////////////////  Main_utils   /////////////////

void		*init_graphics(void);
// int			open_map_file(char *filename);
t_map		*allocate_map(void);
void		validate_and_copy_map(t_data *game, int fd_map, t_map *map,
				char *filename);
void		validate_objects(t_map *map, char **map_copy, t_data *game);

/////////////////  Parsing   /////////////////

void		find_player_pos(t_map *map, char **map_cpy);
void		flood_fill(char **map_copy, t_map *map, int x, int y);
short		objs_are_reachable(t_map *map);
short		check_filename_extention(char *av, char *extention);
void		check_arguments(int ac, char *av, void *mlx_ptr);

/////////////////  Graphics_utils   /////////////////

void		img_to_win(t_data *game, void *img, int x, int y);
void		init_win(t_data *game);
void		display_map(t_data *game, int x_old, int y_old, int update);
void		update_player_position(t_data *game, int x_old, int y_old);
void		draw_tile(t_data *game, char tile, int x, int y);
void		draw_line(t_data *game, int y);

/////////////////  Moves   /////////////////

void		count_and_display_steps(t_data *game);
void		check_collectible(t_data *game, int y, int x);
void		move_up(t_data *game);
void		move_down(t_data *game);
void		move_left(t_data *game);
void		move_right(t_data *game);
int			handle_key(int key, t_data *game);

/////////////////  Hooks   /////////////////

int			handle_keyrelease(int key, t_data *game);
int			handle_destroy(t_data *game);
void		setup_hooks(t_data *game);

/////////////////  Clean   /////////////////

void		clean(t_data *game);
void		clean_textures(t_data *game);
void		clean_alpha(t_data *game);
void		clean_num(t_data *game);
void		clean_assets(t_data *game);
void		find_size_and_free_map(char **map);
void		free_game(t_data *game);
void		free_line(char *line);

/////////////////  Bonus   /////////////////

void		display_header(t_data *game);
void		display_text(t_data *game, int *x, char *text);
void		display_digits(t_data *game, char c, int *x);
void		display_count(t_data *game, int *x, int count);
void		display_char(t_data *game, char c, int *x);
void		*get_alpha_image(t_data *game, char c);
void		*get_special_image(t_data *game, char c);

/////////////////  Init_texture  /////////////////

void		init_textures(t_data *game, int img_size);
void		init_alpha(t_data *game, int img_size);
void		init_num(t_data *game, int img_size);
void		init_and_check_fail_texture(t_data *game, int i, char *path,
				int img_size);
int			init_and_check_fail_alpha(t_data *game, int i, char *path,
				int img_size);
int			init_and_check_fail_num(t_data *game, int i, char *path,
				int img_size);
#endif
