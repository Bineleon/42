# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 14:46:15 by neleon            #+#    #+#              #
#    Updated: 2024/05/31 14:57:15 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER			= server
NAME_CLIENT			= client

SRC					= 

# SRC_BONUS		= main_checker.c checker_moves.c checker.c checker_utils.c\

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g3
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./
BONUS_DIR		= bonus/

OBJ 			= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}
MAIN_OBJ        = ${addprefix ${OBJ_DIR},${SRC_MAIN:.c=.o}}
BONUS_OBJ       = ${addprefix ${OBJ_DIR},${SRC_BONUS:.c=.o}}

INCLUDE 		= -L./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< into $@"
	${CC} ${FLAGS} -c $< -o $@

${OBJ_DIR}%.o: ${BONUS_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< into $@"
	${CC} ${FLAGS} -c $< -o $@

.c.o:
	@echo "Compiling $< into ${<:.c=.o}"
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${MAIN_OBJ} ${OBJ}
	@echo "\nCreating libft.a\n"
	make -C $(LIBFTDIR)
	@echo "\nlibft DONE"
	@echo "\nCreating push_swap\n"
	${CC} ${FLAGS} ${MAIN_OBJ} ${OBJ} -o ${NAME} ${INCLUDE}
	@echo "\npush_swap DONE\n"

${BONUS}: ${OBJ} ${BONUS_OBJ}
	@echo "\nCreating libft.a\n"
	make -C $(LIBFTDIR)
	@echo "\nlibft DONE"
	@echo "\nCreating bonus checker\n"
	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} -o ${BONUS} ${INCLUDE}
	@echo "\nBonus DONE\n"

all: ${NAME}

bonus: ${BONUS}

clean:
	${RM} -rf $(OBJ_DIR) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: fclean all bonus

.PHONY: all clean fclean re bonus
