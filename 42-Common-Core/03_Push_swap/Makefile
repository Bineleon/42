# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 18:22:16 by neleon            #+#    #+#              #
#    Updated: 2024/05/26 17:32:30 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC				= stack_utils.c lst_utils.c check_errors.c\
				push_moves.c swap_moves.c rotate_moves.c rev_rotate_moves.c\
				lst_utils2.c sort_utils.c sort_utils2.c utils.c sort.c cost.c\
				a_to_b.c b_to_a.c prep_sort.c sort_main.c optimize.c optimize_cost.c\
				parsing.c\

SRC_BONUS		= main_checker.c checker_moves.c checker.c checker_utils.c checker.c\

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g3
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./
BONUS_DIR		= bonus/

OBJ = ${addprefix ${OBJ_DIR},${SRC:.c=.o}}

INCLUDE = -L ./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	${RM} -rf $(OBJ_DIR) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	${RM} ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: clean all

.PHONY: all clean fclean re bonus
