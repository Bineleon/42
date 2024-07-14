/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:26:59 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/14 19:06:14 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/////////////////   Map macros   /////////////////

#ifndef WALL
# define WALL '\''
#endif

#ifndef PLAYER
# define PLAYER 'P'
#endif

#ifndef COLLEC
# define COLLEC 'C'
#endif

#ifndef EXIT
# define EXIT 'E'
#endif

#ifndef FLOOR
# define FLOOR ' '
#endif

/////////////////  Game macros  /////////////////

#ifndef KEY_A
# define KEY_A 97
#endif

#ifndef KEY_D
# define KEY_D 100
#endif

#ifndef KEY_W
# define KEY_W 119
#endif

#ifndef KEY_S
# define KEY_S 115
#endif

#ifndef KEY_LEFT
# define KEY_LEFT 65361
#endif

#ifndef KEY_RIGHT
# define KEY_RIGHT 65363
#endif

#ifndef KEY_UP
# define KEY_UP 65362
#endif

#ifndef KEY_DOWN
# define KEY_DOWN 65364
#endif

#ifndef IMG_SIZE
# define IMG_SIZE 75
#endif


# define CHAR_L_PATH "./assets/game/character_left.xpm"
# define CHAR_R_PATH "./assets/game/character_right.xpm"
# define COLLEC_PATH "./assets/game/collec2.xpm"
# define EXIT_PATH "./assets/game/exit2.xpm"
# define FLOOR_PATH "./assets/game/floor.xpm"
# define WALL_PATH "./assets/game/wall2.xpm"

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
# define LR_A "./assets/alpha_num/A.xpm"
# define LR_B "./assets/alpha_num/B.xpm"
# define LR_C "./assets/alpha_num/C.xpm"
# define LR_D "./assets/alpha_num/D.xpm"
# define LR_E "./assets/alpha_num/E.xpm"
# define LR_F "./assets/alpha_num/F.xpm"
# define LR_G "./assets/alpha_num/G.xpm"
# define LR_H "./assets/alpha_num/H.xpm"
# define LR_I "./assets/alpha_num/I.xpm"
# define LR_J "./assets/alpha_num/J.xpm"
# define LR_K "./assets/alpha_num/K.xpm"
# define LR_L "./assets/alpha_num/L.xpm"
# define LR_M "./assets/alpha_num/M.xpm"
# define LR_N "./assets/alpha_num/N.xpm"
# define LR_O "./assets/alpha_num/O.xpm"
# define LR_P "./assets/alpha_num/P.xpm"
# define LR_Q "./assets/alpha_num/Q.xpm"
# define LR_R "./assets/alpha_num/R.xpm"
# define LR_S "./assets/alpha_num/S.xpm"
# define LR_T "./assets/alpha_num/T.xpm"
# define LR_U "./assets/alpha_num/U.xpm"
# define LR_V "./assets/alpha_num/V.xpm"
# define LR_S_MUSH "./assets/alpha_num/S-mush.xpm"
# define LR_SLASH "./assets/alpha_num/slash.xpm"
# define LR_DOUBLE_P "./assets/alpha_num/double-point.xpm"
# define LR_Z "./assets/alpha_num/Z.xpm"

#endif
