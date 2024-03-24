/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:43:35 by neleon            #+#    #+#             */
/*   Updated: 2024/03/24 23:51:53 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/srcs/ft_printf.h"
# include "libft/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	// struct s_stack	*prev;

}					t_stack;

// parsing
void				init_stack(t_stack **stack_a, char **av);

// lst_utils
t_stack				*ft_stacknew(int nb);
void				ft_stackadd_back(t_stack **lst, t_stack *new);

// errors
int					is_duplicate(t_stack *stack_a, int nb);
int					not_digit(char *str);
void				print_error(void);

#endif