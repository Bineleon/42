/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:10:20 by neleon            #+#    #+#             */
/*   Updated: 2023/11/24 20:19:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    while(*s)
    {
        write(fd, s, 1);
        s++;
    }
    write(fd, "\n", 1);
}

// int main(void)
// {
//     ft_putendl_fd("Coucou", 1);
//     return (0);
// }
