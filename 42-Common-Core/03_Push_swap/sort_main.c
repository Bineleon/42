/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:57:14 by neleon            #+#    #+#             */
/*   Updated: 2024/05/23 22:28:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	*join_arguments(int ac, char **av)
{
	char	*joined_args;
	char	*temp;
	int		i;

	if (ac < 2)
		return (NULL);
	joined_args = ft_strjoin("", av[1]);
	i = 2;
	while (i < ac)
	{
		temp = ft_strjoin(joined_args, " ");
		free(joined_args);
		joined_args = ft_strjoin(temp, av[i]);
		free(temp);
		i++;
	}
	return (joined_args);
}

int	is_valid_number_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate_in_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->nb == runner->nb)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
    if (!is_sorted(*a))
    {
        sort_b(a, b);
        sort_three_a(a);
        sort_a(a, b);
        last_sort(a);
    }
}

void check_empty_args(int ac, char **av)
{
    if (ac == 2)
    {
        char *arg = av[1];
        while (*arg)
        {
            if (*arg != ' ')
                return;
            arg++;
        }
        ft_putstr_fd("Error\n", 2);
	    exit(1);
    }
}

void	validate_and_init_stack(t_stack **a, char *joined_args)
{
	if (!joined_args || !is_valid_number_string(joined_args))
	{
		free(joined_args);
		print_error(a);
	}
	init_stack(a, joined_args);
}

void	check_dup_and_sort(t_stack **a, t_stack **b)
{
    if (is_not_int(*a))
        print_error(a);
	if (is_duplicate_in_stack(*a))
		print_error(a);
    if (!is_sorted(*a))
    {
        if (ft_stack_size(*a) == 3)
            sort_three_a(a);
        else
            sort_stack(a, b);
    }
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*joined_args;

	a = NULL;
	b = init_b();
	if (ac > 1)
	{
		check_empty_args(ac, av);
		joined_args = join_arguments(ac, av);
		validate_and_init_stack(&a, joined_args);
		free(joined_args);
		check_dup_and_sort(&a, &b);
		// print_stack(a);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int		i;
// 	t_stack	*a;
// 	t_stack	*b;
// 	char	**split_args;
// 	int		count;

// 	a = NULL;
// 	b = init_b();
// 	split_args = NULL;
// 	i = 1;
// 	if (ac > 1)
// 	{
// 		if (ac == 2 && av[1][0])
// 		{
// 			count = ft_count_words(av[1], ' ');
// 			if (av[1][0] != ' ' && count > 0)
// 				split_args = ft_split(av[1], ' ');
// 			else
// 			{
// 				free(split_args);
// 				print_error(&a);
// 			}
// 			while (i < count)
// 			{
// 				if (not_digit(split_args[i]) || is_duplicate(a,
// 						ft_atoi(split_args[i]))
// 					|| is_not_int(ft_atoi(split_args[i])))
// 					{
// 						free_malloc(split_args, i);
// 						print_error(&a);
// 					}
// 				i++;
// 			}
// 			init_split(&a, split_args);
// 			free(split_args);
// 		}
// 		if (ac > 2)
// 		{
// 			init_stack(&a, av);
// 			while (i < ac)
// 			{
// 				if (not_digit(av[i]) || is_duplicate(a, ft_atoi(av[i]))
// 					|| is_not_int(ft_atoi(av[i])))
// 					print_error(&a);
// 				i++;
// 			}
// 		}
// 		if (ft_stack_size(a) == 3)
// 		{
// 			sort_three_a(&a);
// 			print_stack(a);
// 		}
// 		else
// 		{
// 			sort_b(&a, &b);
// 			sort_three_a(&a);
// 			sort_a(&a, &b);
// 			last_sort(&a);
// 		}
// 		// print_stack(a);
// 		free_stack(&a);
// 		free_stack(&b);
// 	}
// 	return (0);
// }
