/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:26:59 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/14 18:59:47 by bineleon         ###   ########.fr       */
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


# define CHAR_L_PATH "./assets/character_left.xpm"
# define CHAR_R_PATH "./assets/character_right.xpm"
# define COLLEC_PATH "./assets/collec2.xpm"
# define EXIT_PATH "./assets/exit2.xpm"
# define FLOOR_PATH "./assets/floor.xpm"
# define WALL_PATH "./assets/wall2.xpm"

// Chiffres de 0 à 9
# define DIGIT_0 "./assets/0.xpm"
# define DIGIT_1 "./assets/1.xpm"
# define DIGIT_2 "./assets/2.xpm"
# define DIGIT_3 "./assets/3.xpm"
# define DIGIT_4 "./assets/4.xpm"
# define DIGIT_5 "./assets/5.xpm"
# define DIGIT_6 "./assets/6.xpm"
# define DIGIT_7 "./assets/7.xpm"
# define DIGIT_8 "./assets/8.xpm"
# define DIGIT_9 "./assets/9.xpm"

// Lettres de A à Z
# define LETTER_A "./assets/A.xpm"
# define LETTER_B "./assets/B.xpm"
# define LETTER_C "./assets/C.xpm"
# define LETTER_D "./assets/D.xpm"
# define LETTER_E "./assets/E.xpm"
# define LETTER_F "./assets/F.xpm"
# define LETTER_G "./assets/G.xpm"
# define LETTER_H "./assets/H.xpm"
# define LETTER_I "./assets/I.xpm"
# define LETTER_J "./assets/J.xpm"
# define LETTER_K "./assets/K.xpm"
# define LETTER_L "./assets/L.xpm"
# define LETTER_M "./assets/M.xpm"
# define LETTER_N "./assets/N.xpm"
# define LETTER_O "./assets/O.xpm"
# define LETTER_P "./assets/P.xpm"
# define LETTER_Q "./assets/Q.xpm"
# define LETTER_R "./assets/R.xpm"
# define LETTER_S "./assets/S.xpm"
# define LETTER_T "./assets/T.xpm"
# define LETTER_U "./assets/U.xpm"
# define LETTER_V "./assets/V.xpm"
# define LETTER_W "./assets/W.xpm"
# define LETTER_X "./assets/X.xpm"
# define LETTER_Y "./assets/Y.xpm"
# define LETTER_Z "./assets/Z.xpm"

#endif
