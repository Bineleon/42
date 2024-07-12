# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:58:44 by neleon            #+#    #+#              #
#    Updated: 2024/07/12 16:34:16 by bineleon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GREEN			= \033[0;32m\e[1m
# RESET			= \e[0m\033[0m

# NAME			= so_long

# INCS_PATH		= ./include
# CC				= cc
# CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INCS_PATH)
# RM				= rm -rf

# SRC_DIR			= ./srcs
# OBJ_DIR			= ./objs/

# SRCS			= srcs/main.c srcs/check_map.c srcs/utils.c srcs/parsing.c\
# 				srcs/main_parsing.c\

# OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}

# LIBFTDIR		= ./libft/
# INCLUDE 		= -L./libft -lft

# ${OBJ_DIR}%.o: ${SRC_DIR}/%.c
# 	@mkdir -p ${OBJ_DIR}
# 	@${CC} ${CFLAGS} -c $< -o $@

# .c.o:
# 	@echo "Compiling $< into ${<:.c=.o}"
# 	${CC} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR}
# 	@echo "${GREEN}Libft       : DONE!${RESET}"
# 	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} ${INCLUDE}
# 	@echo "${GREEN}So_long     : DONE!${RESET}"

# all: ${NAME}

# ${LIBFT}:
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR}

# clean:
# 	@${RM} ${OBJ_DIR}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
# 	@echo "${GREEN}Clean       : DONE!${RESET}"

# fclean: clean
# 	@${RM} ${NAME}
# 	@${RM} $(OUTPUT_LEAKS)
# 	@echo "${GREEN}Full clean  : DONE!${RESET}"

# re: fclean all

# leaks: all
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=${OUTPUT_LEAKS}  ./${NAME}
# 	@cat valgrind-out.txt

# .PHONY: all clean fclean re show



GREEN			= \033[0;32m\e[1m
RESET			= \e[0m\033[0m

NAME			= so_long

INCS_PATH		= ./include
INC     		= /usr/include
LIBMLX  		= mlx
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH)
LFLAGS			= -L$(LIBMLX) -lmlx
RM				= rm -rf

SRC_DIR			= ./srcs
OBJ_DIR			= ./objs/

SRCS			= srcs/main.c srcs/main_mlx.c srcs/check_map.c srcs/utils.c\
				srcs/parsing.c srcs/map_utils.c srcs/main_clear.c srcs/main_utils.c\
				srcs/graphics_utils.c\

OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}

# OUTPUT_LEAKS	= valgrind-out.txt

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

.c.o:
	@echo "Compiling $< into ${<:.c=.o}"
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft       : DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
	@echo "${GREEN}So_long     : DONE!${RESET}"

all: ${NAME}

${LIBFT}:
	@${MAKE} --no-print-directory -C ${LIBFTDIR}

clean:
	@${RM} ${OBJ_DIR}
	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
	@echo "${GREEN}Clean       : DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@${RM} $(OUTPUT_LEAKS)
	@echo "${GREEN}Full clean  : DONE!${RESET}"

re: fclean all

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=${OUTPUT_LEAKS}  ./${NAME}
	@cat valgrind-out.txt

.PHONY: all clean fclean re show
