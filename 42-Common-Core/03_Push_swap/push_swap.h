/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:43:35 by neleon            #+#    #+#             */
/*   Updated: 2024/03/24 15:28:49 by neleon           ###   ########.fr       */
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
}					t_stack;

#endif