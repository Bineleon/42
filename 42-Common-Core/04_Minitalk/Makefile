# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 14:46:15 by neleon            #+#    #+#              #
#    Updated: 2024/06/17 18:33:31 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m\e[1m
RESET = \e[0m\033[0m

CC = cc
CFLAGS = -Wall -Wextra # -Werror
NAME = server client

SRC_DIR = .
OBJ_DIR = ./objs/

SRCS = server.c client.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)%.o)

LIBFTDIR = ./libft/
LIBFT = ./libft/libft.a

RM = rm -rf

all: $(OBJ_DIR) $(NAME)


bonus: ${NAME}
	@echo "$(GREEN)Bonus build : DONE!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

server: $(OBJ_DIR)server.o ${LIBFT}
	@$(CC) $(CFLAGS) $(OBJ_DIR)server.o ${LIBFT} -o server
	@echo "$(GREEN)Server     : DONE!$(RESET)"

client: $(OBJ_DIR)client.o ${LIBFT}
	@$(CC) $(CFLAGS) $(OBJ_DIR)client.o ${LIBFT} -o client
	@echo "$(GREEN)Client     : DONE!$(RESET)"

${LIBFT}:
	@$(MAKE) --no-print-directory -C $(LIBFTDIR)

clean:
	@${RM} $(OBJ_DIR)
	@${MAKE} --no-print-directory -C $(LIBFTDIR) fclean
	@echo "$(GREEN)Clean      : DONE!$(RESET)"

fclean: clean
	@${RM} ${NAME}
	@echo "$(GREEN)Full clean : DONE!$(RESET)"

re: fclean all

.PHONY: all clean fclean re



# NAME_CLIENT		= client
# NAME_SERVER		= server

# CC				= cc
# FLAGS			= -Wall -Wextra -Werror
# RM				= rm -f

# SRC_SERVER		= server.c
# SRC_CLIENT		= client.c

# OBJ_DIR			= obj/
# OBJ_SERVER		= $(addprefix $(OBJ_DIR), $(SRC_SERVER:.c=.o))
# OBJ_CLIENT		= $(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.o))

# LIBFTDIR			= ./libft
# INCLUDE			= -L./libft -lft

# $(OBJ_DIR)%.o: %.c
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(FLAGS) -c $< -o $@

# $(NAME_SERVER): libft $(OBJ_SERVER)
# 	$(CC) $(FLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(INCLUDE)

# $(NAME_CLIENT): libft $(OBJ_CLIENT)
# 	$(CC) $(FLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(INCLUDE)

# server: $(NAME_SERVER)

# client: $(NAME_CLIENT)

# all: client server

# libft:
# 	$(MAKE) -C $(LIBFTDIR)

# clean:
# 	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
# 	@$(MAKE) -C $(LIBFTDIR) clean

# fclean: clean
# 	@$(RM) -rf $(OBJ_DIR) $(NAME_SERVER) $(NAME_CLIENT)
# 	@$(MAKE) -C $(LIBFTDIR) fclean

# re: fclean all

# .PHONY: all clean fclean re client server libft


# NAME_SERVER		= server
# NAME_CLIENT		= client
# NAME_FULL			= ${NAME_CLIENT} ${NAME_SERVER}

# SRC_SERVER		= server.c
# SRC_CLIENT		= client.c

# CC				= cc
# RM				= rm -f
# FLAGS			= -Wall -Wextra -Werror
# LIBFTDIR		= libft/
# OBJC_DIR		= objc/
# OBJS_DIR		= objs/
# SRC_DIR			= ./

# OBJ_SERVER		= ${addprefix ${OBJS_DIR},${SRC_SERVER:.c=.o}}
# OBJ_CLIENT		= ${addprefix ${OBJC_DIR},${SRC_CLIENT:.c=.o}}

# INCLUDE			= -L./libft -lft

# ${OBJC_DIR}%.o: ${SRC_DIR}%.c
# 	mkdir -p ${OBJC_DIR}
# 	${CC} ${FLAGS} -c $< -o $@

# ${OBJS_DIR}%.o: ${SRC_DIR}%.c
# 	mkdir -p ${OBJS_DIR}
# 	${CC} ${FLAGS} -c $< -o $@

# .c.o:
# 	@echo "Compiling $< into ${<:.c=.o}"
# 	${CC} -c $< -o ${<:.c=.o}

# ${NAME_SERVER}: ${OBJ_SERVER}
# 	make -C ${LIBFTDIR}
# 	${CC} ${FLAGS} ${OBJ_SERVER} -o ${NAME_SERVER} ${INCLUDE}

# ${NAME_CLIENT}: ${OBJ_CLIENT}
# 	make -C ${LIBFTDIR}
# 	${CC} ${FLAGS} ${OBJ_CLIENT} -o ${NAME_CLIENT} ${INCLUDE}

# all: ${NAME_FULL}

# clean:
# 	@${RM} -rf ${OBJC_DIR} -rf ${OBJS_DIR} ${NAME_CLIENT} ${NAME_SERVER}
# 	@cd ${LIBFTDIR} && ${MAKE} clean

# fclean: clean
# 	@${RM} ${NAME_SERVER} ${NAME_CLIENT}
# 	@cd ${LIBFTDIR} && ${MAKE} fclean

# re: fclean all

# .PHONY: all clean fclean re

# NAME_SERVER		= server
# NAME_CLIENT		= client

# SRC_SERVER		= server.c
# SRC_CLIENT		= client.c

# CC				= cc
# RM				= rm -f
# FLAGS			= -Wall -Wextra -Werror
# LIBFTDIR		= libft/
# OBJ_DIR			= obj/
# SRC_DIR			= ./

# OBJ_SERVER		= ${addprefix ${OBJ_DIR},${SRC_SERVER:.c=.o}}
# OBJ_CLIENT		= ${addprefix ${OBJ_DIR},${SRC_CLIENT:.c=.o}}

# INCLUDE			= -L./libft -lft

# ${OBJ_DIR}%.o: ${SRC_DIR}%.c
# 	@mkdir -p ${OBJ_DIR}
# 	@echo "Compiling $< into $@"
# 	@${CC} ${FLAGS} -c $< -o $@

# ${NAME_CLIENT}: ${OBJ_CLIENT}
# 	@echo "\nCreating libft.a client\n"
# 	@make -C ${LIBFTDIR}
# 	@echo "libft DONE"
# 	@echo "\nCreating Minitalk CLIENT\n"
# 	@${CC} ${FLAGS} ${OBJ_CLIENT} -o ${NAME_CLIENT} ${INCLUDE}
# 	@echo "Minitalk CLIENT DONE\n"

# ${NAME_SERVER}: ${OBJ_SERVER}
# 	@echo "\nCreating libft.a server\n"
# 	@make -C ${LIBFTDIR}
# 	@echo "libft DONE"
# 	@echo "\nCreating Minitalk SERVER\n"
# 	@${CC} ${FLAGS} ${OBJ_SERVER} -o ${NAME_SERVER} ${INCLUDE}
# 	@echo "Minitalk SERVER DONE\n"


# all: ${NAME_SERVER} ${NAME_CLIENT}

# clean:
# 	@${RM} -rf ${OBJ_DIR} ${NAME_CLIENT} ${NAME_SERVER}
# 	@cd ${LIBFTDIR} && ${MAKE} clean

# fclean: clean
# 	@${RM} ${NAME_SERVER} ${NAME_CLIENT}
# 	@cd ${LIBFTDIR} && ${MAKE} fclean

# re: fclean all

# .PHONY: all clean fclean re



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
