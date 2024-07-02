/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:28:06 by neleon            #+#    #+#             */
/*   Updated: 2024/07/02 18:29:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/srcs/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

/////////////////  Macro  /////////////////

# ifndef WALL
#  define WALL '\''
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef COLLEC
#  define COLLEC 'C'
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef PATH
#  define PATH ' '
# endif

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
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	*map;
}			t_data;

///////////////// Check_map /////////////////

char		**map_cpy(int map_fd, t_map *map);
int			get_map_fd(char *map_file);
int			is_valid_map(int map_fd, t_map **map);
int			is_valid_top_down_wall(char *line, int *col_count);
int			is_valid_middle_wall(char *line, int col_count, t_map **map);
int			is_valid_format(int map_fd, t_map **map);
int			count_lines(int map_fd, char *map);
void		count_objects(char *line, int *player, int *exit, int *collec);

void		map_size(char *av, t_map *map);
int			map_len(char *line);

/////////////////  Utils   /////////////////

void		ft_mapnew(t_map *map);
void		free_map(t_map *map);
void		free_line(char *line);
void		check_empty_line(char *line, int map_fd);
void		malloc_map(char **map, int line_count);

/////////////////  Parsing   /////////////////

void		find_player_pos(t_map *map, char **map_cpy);
void		flood_fill(char **map_copy, t_map *map, int x, int y);
int			objs_are_reachable(t_map *map);

#endif
