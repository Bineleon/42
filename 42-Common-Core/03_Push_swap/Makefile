# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neleon <neleon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 18:22:16 by neleon            #+#    #+#              #
#    Updated: 2024/03/29 13:57:00 by neleon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC_1			= push_swap.c stack_utils.c lst_utils.c check_errors.c\
				push_moves.c swap_moves.c rotate_moves.c rev_rotate_moves.c\
				lst_utils2.c sort_utils.c sort_utils2.c\

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


# NAME			= push_swap
# LIBFT			= libft/libft/ft_atoi.c libft/libft/ft_bzero.c libft/libft/ft_calloc.c libft/libft/ft_isalnum.c libft/libft/ft_isalpha.c\
# 				libft/libft/ft_isascii.c libft/libft/ft_isdigit.c libft/libft/ft_isprint.c libft/libft/ft_memchr.c libft/libft/ft_itoa.c\
# 				libft/libft/ft_memcmp.c libft/libft/ft_memcpy.c libft/libft/ft_memmove.c libft/libft/ft_memset.c libft/libft/ft_putchar_fd.c\
# 				libft/libft/ft_putendl_fd.c libft/libft/ft_putnbr_fd.c libft/libft/ft_putstr_fd.c libft/libft/ft_split.c\
# 				libft/libft/ft_strchr.c libft/libft/ft_strdup.c libft/libft/ft_striteri.c libft/libft/ft_strjoin.c libft/libft/ft_strlcat.c\
# 				libft/libft/ft_strlcpy.c libft/libft/ft_strlen.c libft/libft/ft_strmapi.c libft/libft/ft_strncmp.c libft/libft/ft_strnstr.c\
# 				libft/libft/ft_strrchr.c libft/libft/ft_strtrim.c libft/libft/ft_substr.c libft/libft/ft_tolower.c libft/libft/ft_toupper.c\
# 				libft/libft/ft_lstnew.c libft/libft/ft_lstadd_front.c libft/libft/ft_lstsize.c\
# 				libft/libft/ft_lstlast.c libft/libft/ft_lstadd_back.c libft/libft/ft_lstdelone.c\
# 				libft/libft/ft_lstclear.c libft/libft/ft_lstiter.c libft/libft/ft_lstmap.c

# PUSH_SWAP		= parse.c main.c\
				
# FT_PRINTF		= libft/ft_printf/srcs/ft_printf.c libft/ft_printf/srcs/ft_puttxt.c libft/ft_printf/srcs/ft_putnbr.c libft/ft_printf/srcs/ft_puthex.c

# HEADER			= push_swap.h

# OBJS			= ${LIBFT:.c=.o} ${FT_PRINTF:.c=.o} ${PUSH_SWAP:.c=.o}

# CC 				= cc
# FLAGS			= -Wall -Wextra -Werror -g3
# RM				= rm -f

# # .c.o:
# # 		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# all:    ${NAME}

# ${NAME}:${OBJS}${HEADER}
# 		${CC} ${CFLAGS} -o ${NAME}${OBJS}

# clean:
# 		${RM} ${OBJS}

# fclean:    clean
# 		${RM} ${NAME} 
        
# re:     fclean all

# .PHONY: all clean fclean re bonus
