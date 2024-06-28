/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:28:06 by neleon            #+#    #+#             */
/*   Updated: 2024/06/28 15:56:04 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/srcs/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "../mlx/mlx.h"
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

// typedef struct s_point
// {
// 	int		x;
// 	int		y;
// }			t_point;

typedef struct s_map
{
	int	collec;
	int	exit;
	int	player;
	int	line_count;
	int	col_count;
}		t_map;

///////////////// Check_map /////////////////

char	**map_cpy(int map_fd, t_map *map);
int		get_map_fd(char *map_file);
int		is_valid_map(int map_fd, t_map *map);
int		is_valid_top_down_wall(char *line, int *col_count);
int		is_valid_middle_wall(char *line, int col_count, t_map **map);
int		is_valid_format(int map_fd, t_map **map);
int		count_lines(int map_fd, char *map);
void	count_objects(char *line, int *player, int *exit, int *collec);

void	map_size(char *av, t_map *map);
int		map_len(char *line);

/////////////////  Utils   /////////////////

void	ft_mapnew(t_map *map);
void	free_map(t_map *map);
void	free_line(char *line);
void	malloc_map(char **map, int line_count);
#endif
