/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:26:59 by bineleon          #+#    #+#             */
/*   Updated: 2024/07/13 17:11:57 by bineleon         ###   ########.fr       */
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

#endif
