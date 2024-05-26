/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:16:21 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 17:48:07 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_a(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_b(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else
		error_checker();
}

void	push_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		push_a(b, a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		push_b(a, b);
	else
		error_checker();
}

void	rotate_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_a(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_b(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else
		error_checker();
}

void	rev_rot_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rev_rotate_a(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		rev_rotate_b(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
		rrr(a, b);
	else
		error_checker();
}

void	mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's')
		swap_mv_read_exe(a, b, line);
	else if (line[0] == 'p')
		push_mv_read_exe(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] != '\n'
		&& line[3] == '\n')
		rev_rot_mv_read_exe(a, b, line);
	else if (line[0] == 'r')
		rotate_mv_read_exe(a, b, line);
	else
		error_checker();
}
