/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:43:35 by neleon            #+#    #+#             */
/*   Updated: 2024/04/10 15:31:22 by neleon           ###   ########.fr       */
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
	int				index;
	int				is_in_top;
	int				moves_to_top;
	struct s_stack	*next;
}					t_stack;

// parsing
void				init_stack(t_stack **stack_a, char **av);
void				init_split(t_stack **stack_a, char **av);

// lst_utils
t_stack				*ft_stacknew(int nb);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
int					ft_stack_size(t_stack *lst);
int					is_first(t_stack *lst, int nb);
int					mid_stack(t_stack *lst);
void				index_in_stack(t_stack *lst);
t_stack				*before_last(t_stack *lst);

// errors
int					is_duplicate(t_stack *stack_a, int nb);
int					not_digit(char *str);
int					is_not_int(long nbr);
void				print_error(void);

// prints
void				print_stack(t_stack *stack);

// swap_moves
void				push_top_to_stack(t_stack **src, t_stack **dst);
void				swap(t_stack **top);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				ss(t_stack **a, t_stack **b);

// rotate_moves
void				rotate(t_stack **top);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rev_rotate(t_stack **top);
void				rev_rotate_a(t_stack **a);
void				rev_rotate_b(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// sort
void				sort_three_a(t_stack **lst);
int					is_rev_sort_three(t_stack *lst);
int					is_sorted(t_stack *lst);
void				moves_calcul(t_stack *lst);
t_stack				*find_node(t_stack *lst, int nb);
t_stack				*find_max(t_stack *lst);
t_stack				*find_min(t_stack *lst);

int					ft_count_words(char const *s, char c);

#endif
