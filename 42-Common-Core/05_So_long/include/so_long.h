/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:28:06 by neleon            #+#    #+#             */
/*   Updated: 2024/07/13 15:29:02 by bineleon         ###   ########.fr       */
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
	t_point	player_pos;
	char  **map;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[6];
	void  *ptr_img_collec;
	void  *ptr_img_exit;
	void  *ptr_img_char_left;
	void  *ptr_img_char_right;
	void  *ptr_img_wall;
	void  *ptr_img_floor;
	t_map	*map;
}			t_data;

///////////////// Check_map /////////////////

char	**map_cpy(int map_fd, t_map *map);
int		get_map_fd(char *map_file);
int		is_valid_map(int map_fd, t_map **map);
int		is_valid_top_down_wall(char *line, int *col_count);
int		is_valid_middle_wall(char *line, int col_count, t_map **map);
int		is_valid_format(int map_fd, t_map **map);
int		count_lines(int map_fd, char *map);
void	count_objects(char *line, int *player, int *exit, int *collec);

void	map_size(char *av, t_map *map);
int		map_len(char *line);
void    init_map(t_map *map);

/////////////////  Utils   /////////////////

void	ft_mapnew(t_map *map);
void	free_map(t_map *map);
void	free_line(char *line);
void	check_empty_line(char *line, int map_fd);
void	malloc_map(char **map, int line_count);
void    init_data(t_data *game, t_map *map);

/////////////////  Main_utils   /////////////////

void *init_graphics();
void check_arguments(int ac);
int open_map_file(char *filename);
t_map	*allocate_map();
char **validate_and_copy_map(int fd_map, t_map *map, char *filename);
void validate_objects(t_map *map, char **map_copy);
void free_resources(char **map_copy, t_map *map, int fd_map);

/////////////////  Parsing   /////////////////

void		find_player_pos(t_map *map, char **map_cpy);
void		flood_fill(char **map_copy, t_map *map, int x, int y);
int			objs_are_reachable(t_map *map);

/////////////////  Graphics_utils   /////////////////

void	assign_img_ptr(t_data *game);
void	init_win(t_data *game);
void display_map(t_data *game);

#endif
