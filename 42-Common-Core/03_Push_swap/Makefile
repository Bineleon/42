# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 18:22:16 by neleon            #+#    #+#              #
#    Updated: 2024/05/15 16:25:57 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC_1			= stack_utils.c lst_utils.c check_errors.c\
				push_moves.c swap_moves.c rotate_moves.c rev_rotate_moves.c\
				lst_utils2.c sort_utils.c sort_utils2.c utils.c sort.c cost.c\
				a_to_b.c b_to_a.c prep_sort.c sort_main.c optimize.c optimize_cost.c\

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g3
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./

OBJ_1 = ${addprefix ${OBJ_DIR},${SRC_1:.c=.o}}

INCLUDE = -L ./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}


clean:
	${RM} -rf $(OBJ_DIR) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	${RM} ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: clean all

.PHONY: all clean fclean re bonus
