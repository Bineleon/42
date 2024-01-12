/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:15:43 by neleon            #+#    #+#             */
/*   Updated: 2024/01/10 17:35:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *calloc_gnl()
{
    
}

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ptr;

    i = 0;
    ptr = (unsigned char *) s;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}
