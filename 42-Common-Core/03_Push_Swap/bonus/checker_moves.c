/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:16:21 by neleon            #+#    #+#             */
/*   Updated: 2024/05/26 23:20:15 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
    {
		swap(a);
        swap(b);
    }
	else
		error_checker();
}

void	push_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_top_to_stack(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_top_to_stack(a, b);
	else
		error_checker();
}

void	rotate_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		{
            rotate(a);
            rotate(b);
        }
	else
		error_checker();
}

void	rev_rot_mv_read_exe(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rev_rotate(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		rev_rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
        {
            rev_rotate(a);
            rev_rotate(b);
        }

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
