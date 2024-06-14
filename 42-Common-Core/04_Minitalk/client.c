/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:41:02 by neleon            #+#    #+#             */
/*   Updated: 2024/06/14 19:31:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver = 0;

void	s_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
	{
		ft_printf("\033[1;32mOH yeah, server got your message\033[0m");
		if (i / 8 > 100)
			ft_printf("\033[1;32m and it's a big one too: %d bytes fat 😱\033[0m\n", i / 8);
		else
			ft_printf("\033[1;32m but it's so small, only %d byte(s)🤏🥺\033[0m\n", i / 8);
	}
			
	else if (signum == SIGINT)
		exit(EXIT_SUCCESS);
}

int	char_to_bin(char c, int pid)
{
	int	bit_index;
	int	i;

	bit_index = 7;
	while (bit_index >= 0)
	{
		i = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (i == MAX_ATTEMPTS)
			{
				ft_printf("Oops, no response from server.\n");
				exit(1);
			}
			i++;
			usleep(ATTEMPT_DELAY);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

void	args_error(int ac, int pid)
{
	if (pid < 0)
	{
		ft_printf("\033[1;33mHep hep hep!!\033[0m");
		ft_printf("\033[1;33m I'm not falling for that 💩!\n\033[0m");
		ft_printf("\033[1;33mTry again with a valid PID babe!\n\033[0m");
		exit(EXIT_FAILURE);
	}
	if (ac != 3)
	{
		ft_printf("\033[1;35mHep hep hep!!\033[0m");
		ft_printf("\033[1;35m You need to put 2 args, not %d\n\033[0m", ac - 1);
		exit(EXIT_FAILURE);
	}
}

void	string_to_bin(int pid, char **av)
{
	int	byte_index;

	byte_index = 0;
	while (av[2][byte_index])
	{
		char_to_bin(av[2][byte_index], pid);
		byte_index++;
	}
	char_to_bin('\0', pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	int					byte_index;

	byte_index = 0;
	pid = ft_atoi(av[1]);
	args_error(ac, pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = s_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Sigaction error\n", 2);
		return (1);
	}
	string_to_bin(pid, av);
	return (0);
}
