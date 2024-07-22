# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:58:44 by neleon            #+#    #+#              #
#    Updated: 2024/07/22 17:10:49 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			= \033[0;32m\e[1m
RESET			= \e[0m\033[0m

NAME			= so_long
NAME_BONUS		= so_long_bonus

INCS_PATH		= ./include
INC     		= /usr/include
LIBMLX  		= ./mlx/
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH)
LFLAGS			= -L$(LIBMLX) -lmlx
RM				= rm -rf

SRC_DIR			= ./srcs
SRC_DIR_B		= ./bonus
OBJ_DIR			= ./objs/
OBJ_DIR_B		= ./objs_bonus/

SRCS			= srcs/map_utils.c srcs/main_utils.c srcs/main.c srcs/clean.c srcs/free.c srcs/game_allocation.c\
				srcs/graphics_operations.c srcs/hooks.c srcs/init_assets.c\
				srcs/map_cleanup.c srcs/map_flood_fill.c srcs/map_handling.c\
				srcs/map_operations.c srcs/map_validation.c srcs/moves.c\
				srcs/parsing.c srcs/player_operations.c srcs/map_cpy_utils.c\

SRCS_BONUS		= bonus/header_utils.c bonus/init_assets_bonus.c bonus/graphics_operations.c\
				bonus/map_utils.c bonus/main_utils.c bonus/main.c bonus/clean.c bonus/free.c bonus/game_allocation.c\
				bonus/hooks.c bonus/init_assets.c bonus/header_utils2.c bonus/map_init.c\
				bonus/map_cleanup.c bonus/map_flood_fill.c bonus/map_handling.c\
				bonus/map_operations.c bonus/map_validation.c bonus/moves.c\
				bonus/parsing.c bonus/player_operations.c bonus/map_cpy_utils.c\

OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
OBJS_BONUS		= ${SRCS_BONUS:${SRC_DIR_B}/%.c=${OBJ_DIR_B}%.o}


LIBFTDIR		= ./libft/
INCLUDE 		= -L./libft -lft


ifeq ($(UNAME), Darwin)
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	CC = clang
else
	CC = cc
	LFLAGS += -lbsd -lXext -lX11 -lm
	CFLAGS += -D LINUX
endif

${OBJ_DIR}%.o: ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR_B}%.o: ${SRC_DIR_B}/%.c
	@mkdir -p ${OBJ_DIR_B}
	@${CC} ${CFLAGS} -c $< -o $@

.c.o:
	@echo "Compiling $< into ${<:.c=.o}"
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft       : DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
	@echo "${GREEN}So_long     : DONE!${RESET}"

${NAME_BONUS}: ${OBJS_BONUS}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft         : DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LFLAGS} ${LIBFT} -o ${NAME_BONUS} ${INCLUDE}
	@echo "${GREEN}So_long bonus : DONE!${RESET}"

all: ${NAME}

${LIBFT}:
	@${MAKE} --no-print-directory -C ${LIBFTDIR}

bonus: ${NAME_BONUS}

clean:
	@${RM} ${OBJ_DIR} ${OBJ_DIR_B}
	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
	@echo "${GREEN}Clean       : DONE!${RESET}"

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@${RM} $(OUTPUT_LEAKS)
	@echo "${GREEN}Full clean  : DONE!${RESET}"

re: fclean all

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./${NAME}

.PHONY: all clean fclean re show leaks bonus
