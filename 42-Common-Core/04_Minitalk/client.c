/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:41:02 by neleon            #+#    #+#             */
/*   Updated: 2024/06/13 14:20:52 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver = 0;

void	s_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	// i = 0;
	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("OH yeah, server got the sig and it's %d bytes fat\n", i / 8);
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
			if (i == 100)
			{
				ft_printf("Oops, no response from server.\n");
				exit(1);
			}
			i++;
			usleep(100);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;
	int					byte_index;

	byte_index = 0;
	if (argc != 3)
	{
		printf("Hep hep hep!! You need to put 2 args, not %d\n", argc - 1);
		return (1);
	}
	pid = atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = s_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
        || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Sigaction error\n", 2);
		return (1);
	}
	while (argv[2][byte_index])
	{
		char_to_bin(argv[2][byte_index], pid);
		byte_index++;
	}
	char_to_bin('\n', pid);
	char_to_bin('\0', pid);
	return (0);
}
