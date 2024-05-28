# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 18:22:16 by neleon            #+#    #+#              #
#    Updated: 2024/05/28 21:40:20 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS			= checker

SRC_MAIN		= sort_main.c

SRC				= stack_utils.c lst_utils.c check_errors.c\
				push_moves.c swap_moves.c rotate_moves.c rev_rotate_moves.c\
				lst_utils2.c sort_utils.c sort_utils2.c utils.c sort.c cost.c\
				a_to_b.c b_to_a.c prep_sort.c optimize.c optimize_cost.c\
				parsing.c\

SRC_BONUS		= main_checker.c checker_moves.c checker.c checker_utils.c\

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
