/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:40:58 by neleon            #+#    #+#             */
/*   Updated: 2024/06/14 17:56:25 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
	else if (signum == SIGINT)
		exit(EXIT_SUCCESS);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static int	i = 0;
	static char	c = 0;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

void	print_border(void)
{
	int			i;
	const char	*colors[6];

	i = -1;
	colors[0] = "\033[1;31m";
	colors[1] = "\033[1;33m";
	colors[2] = "\033[1;32m";
	colors[3] = "\033[1;36m";
	colors[4] = "\033[1;34m";
	colors[5] = "\033[1;35m";
	ft_printf(" ");
	while (++i < 42)
		ft_printf("%s*\033[0m", colors[i % 6]);
	ft_printf("\n");
}

void	welcome_message(void)
{
	print_border();
	ft_printf(" \033[1;31m*                                        *\033[0m\n");
	ft_printf(" \033[1;32m*  Hello hello and welcome dear visitors *\033[0m\n");
	ft_printf(" \033[1;33m*                    *                   *\033[0m\n");
	sleep(2);
	ft_printf(" \033[1;36m*                                        *\033[0m\n");
	ft_printf(" \033[1;32m*         You feel chatty today ?        *\033[0m\n");
	ft_printf(" \033[1;35m*                    *                   *\033[0m\n");
	sleep(2);
	ft_printf(" \033[1;34m*                                        *\033[0m\n");
	ft_printf(" \033[1;32m* And I bet you wanna get my server PID, *\033[0m\n");
	ft_printf(" \033[1;32m*              n'est-ce pas?             *\033[0m\n");
	ft_printf(" \033[1;31m*                    *                   *\033[0m\n");
	sleep(2);
	ft_printf(" \033[1;33m*                                        *\033[0m\n");
	ft_printf(" \033[1;32m*         Well...here...it...is          *\033[0m\n");
	ft_printf(" \033[1;36m*                    *                   *\033[0m\n");
	sleep(2);
	print_border();
	ft_printf("\n\033[1;31m         *****  PID : %d  *****\033[0m\n", getpid());
}

int	main(void)
{
	struct sigaction	sa;

	welcome_message();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Oops! Sigaction error");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Oops! Sigaction error");
		return (1);
	}
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
	return (0);
}
