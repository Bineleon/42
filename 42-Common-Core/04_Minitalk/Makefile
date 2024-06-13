# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 14:46:15 by neleon            #+#    #+#              #
#    Updated: 2024/06/13 19:47:19 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAME			= server client

# SRC				= server.c client.c

# CC				= cc
# RM				= rm -f
# FLAGS			= -Wall -Wextra -Werror
# LIBFTDIR		= libft/
# OBJ_DIR			= obj/
# SRC_DIR			= ./

# OBJ				= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}

# INCLUDE			= -L./libft -lft

# ${OBJ_DIR}%.o: ${SRC_DIR}%.c
# 	@mkdir -p ${OBJ_DIR}
# 	@echo "Compiling $< into $@"
# 	@${CC} ${FLAGS} -c $< -o $@

# ${NAME}: ${OBJ} 
# 	@echo "\nCreating libft.a\n"
# 	@make -C ${LIBFTDIR}
# 	@echo "libft DONE"
# 	@echo "\nCreating Minitalk \n"
# 	@${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
# 	@echo "Minitalk DONE\n"
	
# all: ${NAME}

# clean:
# 	@${RM} -rf ${OBJ_DIR} ${NAME}
# 	@cd ${LIBFTDIR} && ${MAKE} clean

# fclean: clean
# 	@${RM} ${NAME}
# 	@cd ${LIBFTDIR} && ${MAKE} fclean

# re: fclean all

# .PHONY: all clean fclean re

NAME_SERVER		= server
NAME_CLIENT		= client

SRC_SERVER		= server.c
SRC_CLIENT		= client.c

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./

OBJ_SERVER		= ${addprefix ${OBJ_DIR},${SRC_SERVER:.c=.o}}
OBJ_CLIENT		= ${addprefix ${OBJ_DIR},${SRC_CLIENT:.c=.o}}

INCLUDE			= -L./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OBJ_DIR}
	@echo "Compiling $< into $@"
	@${CC} ${FLAGS} -c $< -o $@

${NAME_CLIENT}: ${OBJ_CLIENT}
	@echo "\nCreating libft.a client\n"
	@make -C ${LIBFTDIR}
	@echo "libft DONE"
	@echo "\nCreating Minitalk CLIENT\n"
	@${CC} ${FLAGS} ${OBJ_CLIENT} -o ${NAME_CLIENT} ${INCLUDE}
	@echo "Minitalk CLIENT DONE\n"
	
${NAME_SERVER}: ${OBJ_SERVER}
	@echo "\nCreating libft.a server\n"
	@make -C ${LIBFTDIR}
	@echo "libft DONE"
	@echo "\nCreating Minitalk SERVER\n"
	@${CC} ${FLAGS} ${OBJ_SERVER} -o ${NAME_SERVER} ${INCLUDE}
	@echo "Minitalk SERVER DONE\n"

	
all: ${NAME_SERVER} ${NAME_CLIENT}

clean:
	@${RM} -rf ${OBJ_DIR} ${NAME_CLIENT} ${NAME_SERVER}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	@${RM} ${NAME_SERVER} ${NAME_CLIENT}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re



# NAME_SERVER		= server
# NAME_CLIENT		= client

# SRC				= *.c

# CC				= cc
# RM				= rm -f
# FLAGS			= -Wall -Wextra -Werror
# LIBFTDIR		= libft/
# OBJ_DIR			= obj/
# SRC_DIR			= ./
# # BONUS_DIR		= bonus/

# OBJ 			= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}
# # # BONUS_OBJ		= ${addprefix ${OBJ_DIR},${SRC_BONUS:.c=.o}}

# INCLUDE 		= -L./libft -lft

# ${OBJ_DIR}%.o: ${SRC_DIR}%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Compiling $< into $@"
# 	@${CC} ${FLAGS} -c $< -o $@

# # # ${OBJ_DIR}%.o: ${BONUS_DIR}%.c
# # # 	@mkdir -p $(OBJ_DIR)
# # # 	@echo "Compiling $< into $@"
# # # 	${CC} ${FLAGS} -c $< -o $@

# .c.o:
# 	@echo "Compiling $< into ${<:.c=.o}"
# 	@${CC} -c $< -o ${<:.c=.o}

# ${NAME_SERVER}: ${OBJ}
# 	@echo "\nCreating libft.a\n"
# 	@make -C $(LIBFTDIR)
# 	@echo "libft DONE"
# 	@echo "\nCreating Minitalk SERVER\n"
# 	@${CC} ${FLAGS} ${OBJ} -o ${NAME_SERVER} ${INCLUDE}
# 	@echo "Minitalk SERVER DONE\n"

# ${NAME_CLIENT}: ${OBJ}
# 	@echo "Creating libft.a\n"
# 	@make -C $(LIBFTDIR)
# 	@echo "libft DONE"
# 	@echo "\nCreating Minitalk CLIENT\n"
# 	@${CC} ${FLAGS} ${OBJ} -o ${NAME_CLIENT} ${INCLUDE}
# 	@echo "Minitalk CLIENT DONE\n"

# # # ${BONUS}: ${OBJ} ${BONUS_OBJ}
# # # 	@echo "\nCreating libft.a\n"
# # # 	make -C $(LIBFTDIR)
# # # 	@echo "\nlibft DONE"
# # # 	@echo "\nCreating bonus checker\n"
# # # 	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} -o ${BONUS} ${INCLUDE}
# # # 	@echo "\nBonus DONE\n"

# all: ${NAME_SERVER} ${NAME_CLIENT}

# # # bonus: ${BONUS}

# clean:
# 	${RM} -rf $(OBJ_DIR) ${NAME_SERVER} ${NAME_CLIENT}
# 	@cd ${LIBFTDIR} && ${MAKE} clean

# fclean: clean
# 	${RM} ${NAME_SERVER} ${NAME_CLIENT}
# 	@cd ${LIBFTDIR} && ${MAKE} fclean

# re: fclean all

# .PHONY: all clean fclean re
# # # .SILENT: all
