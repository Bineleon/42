/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putHex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:28 by neleon            #+#    #+#             */
/*   Updated: 2023/12/08 16:13:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.>

void ft_putbase(unsigned long nb, char *base, int *count);

void ft_ptohex(va_list pa, int *count)
{
	char *hex;
	unsigned long p;
	
	hex = "0123456789abcdef";
	p = va_arg(pa, unsigned long);
	ft_putbase(p, hex, count);
}

void ft_putbase(unsigned long nb, char *base, int *count)
{
	if (nb > 15)
		ft_putbase(nb / base, base, count);
	ft_putchar_fd(base[nb % 10], 1);
	*count += 1;
}