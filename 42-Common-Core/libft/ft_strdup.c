/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:00:44 by neleon            #+#    #+#             */
/*   Updated: 2023/11/10 19:06:51 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);

char *ft_strdup(const char *s1)
{
    size_t  len;
    char    *str;
    int i;

    i = 0;
    len = ft_strlen(s1);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

// int main(int ac, char **av)
// {
//     if (ac == 2)
//     {
//         char *s1 = ft_strdup(av[1]);

//         printf("%s : %s\n", av[1], s1);
//         free(s1);
//     }

//     return (0);
// }
