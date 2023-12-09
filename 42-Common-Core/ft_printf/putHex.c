/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putHex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:28 by neleon            #+#    #+#             */
/*   Updated: 2023/12/09 16:58:14 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>


void ft_putbase(unsigned long nb, char *base);

void	ft_putchar_fd(char c, int fd)
{
	write(1, &c, fd);
}

// void ft_ptohex(va_list pa, int *count)
// {
// 	char *hex;
// 	unsigned long p;

// 	hex = "0123456789abcdef";
// 	p = va_arg(pa, unsigned long);
// 	ft_putbase(p, hex, count);
// }

// void ft_nbrtohex(va_list pa, char x, int *count)
// {
//     char *lowerhex;
//     char *upperhex;
//     unsigned long nb;

//     nb = va_arg(pa, int);
//     lowerhex = "0123456789abcdef";
//     lowerhex = "0123456789ABCDEF";
//     if (x == 'x')
//         ft_putbase(nb, lowerhex, count);
//     else if (x == 'X')
//         ft_putbase(nb, upperhex, count);
// }

void ft_putbase(unsigned long nb, char *base)
{
	if (nb > 15)
		ft_putbase(nb / 16, base);
	ft_putchar_fd(base[nb % 16], 1);
	// *count += 1;
}

void ft_nbrtohex(unsigned long nb, char x)
{
    char *lowerhex;
    char *upperhex;
    // unsigned long nb;

    // nb = va_arg(pa, int);
    lowerhex = "0123456789abcdef";
    upperhex = "0123456789ABCDEF";
    if (x == 'x')
        ft_putbase(nb, lowerhex);
    else if (x == 'X')
        ft_putbase(nb, upperhex);
}
#include <stdio.h>

int main(void)
{
    unsigned long nb = 250455495;
    printf("%lu in hexa is :", nb);
    ft_nbrtohex(nb, 'X');
    printf("%lX\n", nb);
}
