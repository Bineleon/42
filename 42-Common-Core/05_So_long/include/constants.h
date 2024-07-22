/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:26:59 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/22 17:15:31 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/////////////////   Map macros   /////////////////

# ifndef WALL
#  define WALL '1'
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

# ifndef FLOOR
#  define FLOOR '0'
# endif

/////////////////  Game macros  /////////////////

# ifndef KEY_A
#  define KEY_A 97
# endif

# ifndef KEY_D
#  define KEY_D 100
# endif

# ifndef KEY_W
#  define KEY_W 119
# endif

# ifndef KEY_S
#  define KEY_S 115
# endif

# ifndef KEY_LEFT
#  define KEY_LEFT 65361
# endif

# ifndef KEY_RIGHT
#  define KEY_RIGHT 65363
# endif

# ifndef KEY_UP
#  define KEY_UP 65362
# endif

# ifndef KEY_DOWN
#  define KEY_DOWN 65364
# endif

# ifndef IMG_SIZE
#  define IMG_SIZE 75
# endif

// Couleurs ANSI

# define RESET "\033[0m"
# define ROUGE "\033[0;31m"
# define VERT "\033[0;32m"
# define JAUNE "\033[0;33m"
# define BLEU "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLANC "\033[0;37m"

# define FLOOR_PATH "./assets/game/floor.xpm"
# define WALL_PATH "./assets/game/wall2.xpm"
# define COLLEC_PATH "./assets/game/collec2.xpm"
# define CHAR_L_PATH "./assets/game/character_left.xpm"
# define CHAR_R_PATH "./assets/game/character_right.xpm"
# define EXIT_PATH "./assets/game/exit2.xpm"

// Chiffres de 0 à 9
# define D_0 "./assets/alpha_num/0.xpm"
# define D_1 "./assets/alpha_num/1.xpm"
# define D_2 "./assets/alpha_num/2.xpm"
# define D_3 "./assets/alpha_num/3.xpm"
# define D_4 "./assets/alpha_num/4.xpm"
# define D_5 "./assets/alpha_num/5.xpm"
# define D_6 "./assets/alpha_num/6.xpm"
# define D_7 "./assets/alpha_num/7.xpm"
# define D_8 "./assets/alpha_num/8.xpm"
# define D_9 "./assets/alpha_num/9.xpm"

// Lettres de A à Z
# define LR_C "./assets/alpha_num/C.xpm"
# define LR_E "./assets/alpha_num/e.xpm"
# define LR_N "./assets/alpha_num/n.xpm"
# define LR_O "./assets/alpha_num/o.xpm"
# define LR_P "./assets/alpha_num/p.xpm"
# define LR_S "./assets/alpha_num/S.xpm"
# define LR_S_MIN "./assets/alpha_num/s.xpm"
# define LR_T "./assets/alpha_num/t.xpm"
# define LR_U "./assets/alpha_num/u.xpm"
# define LR_SLASH "./assets/alpha_num/slash.xpm"
# define LR_DOUBLE_P "./assets/alpha_num/double_point.xpm"

#endif
