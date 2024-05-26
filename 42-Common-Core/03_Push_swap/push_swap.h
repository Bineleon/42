/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:43:35 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 19:15:41 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/srcs/ft_printf.h"
# include "libft/gnl/get_next_line_bonus.h"
# include "libft/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	long			nb;
	int				index;
	int				is_in_top;
	int				total_cost;
	int				target_cost;
	int				segment;
	int				is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

// parsing
void				check_empty_args(int ac, char **av);
char				*join_arguments(int ac, char **av);

// lst_utils
t_stack				*ft_stacknew(long nb);
t_stack				*ft_stacklast(t_stack *lst);
t_stack				*before_last(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
int					ft_stack_size(t_stack *lst);
int					is_first(t_stack *lst, int nb);
int					mid_stack(t_stack *lst);

// errors
int					check_duplicate_in_stack(t_stack *stack);
int					is_valid_number_string(char *str);
int					is_not_int(t_stack *stack);
void				print_error(t_stack **stack);

// prints
void				print_stack(t_stack *stack);

// stack_utils
t_stack				*init_b(void);
void				init_stack(t_stack **stack_a, char *joined_args);
void				validate_and_init_stack(t_stack **a, char *joined_args);
void				check_dup_and_sort(t_stack **a, t_stack **b);
void				free_stack(t_stack **lst);

// push_moves
void				push_top_to_stack(t_stack **src, t_stack **dst);
void				push_a(t_stack **b, t_stack **a);
void				push_b(t_stack **a, t_stack **b);

// swap_moves
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

// opti
void				assign_segment(t_stack **a, int pivots[3]);
void				fill_arr(t_stack *stack, int **arr);
int					partition(int arr[], int low, int high);
int					quick_select(int arr[], int low, int high, int k);
int					*find_pivots(t_stack *stack, int size, int *pivots);

//  prep_sort
void				index_in_stack(t_stack **lst);
void				prep_stack_a(t_stack **a);
void				prep_stack_b(t_stack **b, t_stack **a);

//  cost
t_stack				*find_cheapest(t_stack *a);
void				assign_cost_in_a(t_stack **a);
void				get_cheapest_by_segment(t_stack **a, int seg);
void				set_cheapest_to_null(t_stack **lst);
void				get_cheapest(t_stack **stack);
void				target_cost(t_stack **a, t_stack **b);
void				total_cost(t_stack *a, t_stack *b);
int					calculate_node_cost(t_stack *node, int stack_length);

// a_to_b
void				node_to_top(t_stack **a, t_stack *node);
void				single_rotate(t_stack **stack, int count,
					void (*move)(t_stack **));
void				double_rotate(t_stack **a, t_stack **b, int count,
					void (*move)(t_stack **, t_stack **));

// b_to_a
void				find_target_b_in_a(t_stack *b, t_stack *a);
void				both_to_top(t_stack **b, t_stack *cheapest, t_stack **a,
						int cost_b);
void				b_and_target_to_top(t_stack **b, t_stack *cheapest,
						t_stack **a);

// sort
t_stack				*find_max(t_stack *lst);
t_stack				*find_min(t_stack *lst);
void				sort_main(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a, t_stack **b);
void				sort_three_a(t_stack **lst);
void				sort_b(t_stack **a, t_stack **b);
void				cheapest_cost(t_stack *a);
void				find_target(t_stack **a, t_stack **b);
void				a_and_target_to_top(t_stack **a, t_stack *cheapest,
						t_stack **b);
void				last_sort(t_stack **a);
void				sort_a(t_stack **a, t_stack **b);
int					is_rev_sort_three(t_stack *lst);
int					is_sorted(t_stack *lst);
int					is_sorted_b(t_stack *lst);

// utils
void				ft_swap(int *a, int *b);
int					ft_count_words(char const *s, char c);
int					ft_min(int cost_a, int cost_b);

// Bonus
void				error_checker(void);
void				swap_mv_read_exe(t_stack **a, t_stack **b, char *line);
void				push_mv_read_exe(t_stack **a, t_stack **b, char *line);
void				rotate_mv_read_exe(t_stack **a, t_stack **b, char *line);
void				rev_rot_mv_read_exe(t_stack **a, t_stack **b, char *line);
void				mv_read_exe(t_stack **a, t_stack **b, char *line);
void				checker(t_stack **a, t_stack **b, char *line);
void				prep_main(int ac, char **av, t_stack **a);

#endif
