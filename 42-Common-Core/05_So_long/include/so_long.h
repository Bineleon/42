/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:28:06 by neleon            #+#    #+#             */
/*   Updated: 2024/06/26 12:59:36 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/srcs/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# ifndef WALL
#  define WALL '\''
# endif

# ifndef PLAYER
#  define PLAYER "P"
# endif

# ifndef COLLEC
#  define COLLEC "C"
# endif

# ifndef EXIT
#  define EXIT "E"
# endif

# ifndef PATH
#  define PATH " "
# endif

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	int		colec;
	int		exit;
	int		player;
	t_point	size;
}			t_map;

// Check_map
char		**map_cpy(int map_fd);
int			get_map_fd(char *map_file);
int			is_valid_map(int map_fd, t_map *map);
int			is_valid_wall_line(char *line);

#endif
