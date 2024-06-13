/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:40:58 by neleon            #+#    #+#             */
/*   Updated: 2024/06/13 14:52:13 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bin_to_char(int signum, char *c)
{
    if (signum == SIGUSR1)
        *c = (*c << 1) | 1;
    else if (signum == SIGUSR2)
        *c <<= 1;
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
    static int pid = 0;
    static int i = 0;
    static char c = 0;

    (void)context;

    if (pid == 0)
        pid = info->si_pid;

    bin_to_char(signum, &c);

    if (++i == 8)
    {
        i = 0;
        if (c == '\0')
        {
            kill(pid, SIGUSR1);
            pid = 0;
            return;
        }
        write(1, &c, 1);
        c = 0;
    }
    kill(pid, SIGUSR2);
}

int main(void)
{
    struct sigaction sa;

    printf("Server PID: %d\n", getpid());

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        ft_printf("Oops! Sigaction error");
        return 1;
    }
    while (1)
        pause();
    return 0;
}
