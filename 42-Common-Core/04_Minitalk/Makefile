# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 14:46:15 by neleon            #+#    #+#              #
#    Updated: 2024/06/03 12:13:44 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER			= server
NAME_CLIENT			= client

SRC					= client.c server.c\

# SRC_BONUS		= main_checker.c checker_moves.c checker.c checker_utils.c\

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g3
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./
BONUS_DIR		= bonus/

OBJ 			= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}
# MAIN_OBJ        = ${addprefix ${OBJ_DIR},${SRC_MAIN:.c=.o}}
# BONUS_OBJ       = ${addprefix ${OBJ_DIR},${SRC_BONUS:.c=.o}}

INCLUDE 		= -L./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< into $@"
	${CC} ${FLAGS} -c $< -o $@

# ${OBJ_DIR}%.o: ${BONUS_DIR}%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Compiling $< into $@"
# 	${CC} ${FLAGS} -c $< -o $@

.c.o:
	@echo "Compiling $< into ${<:.c=.o}"
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@echo "\nCreating libft.a\n"
	make -C $(LIBFTDIR)
	@echo "\nlibft DONE"
	@echo "\nCreating nMinitalk\n"
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
	@echo "\nMinitalk DONE\n"

# ${BONUS}: ${OBJ} ${BONUS_OBJ}
# 	@echo "\nCreating libft.a\n"
# 	make -C $(LIBFTDIR)
# 	@echo "\nlibft DONE"
# 	@echo "\nCreating bonus checker\n"
# 	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} -o ${BONUS} ${INCLUDE}
# 	@echo "\nBonus DONE\n"

all: ${NAME}

# bonus: ${BONUS}

clean:
	${RM} -rf $(OBJ_DIR) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	${RM} ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re
