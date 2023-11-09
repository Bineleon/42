/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:15:59 by neleon            #+#    #+#             */
/*   Updated: 2023/11/09 18:55:40 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    int i;

    i = 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    while (n-- > 0)
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(void)
{
    const char s1[] = "hello, it's me";
    const char s2[] = "Couco, it's me";
    size_t n = ft_strlen(s1);
    printf("the difference is : %d\n", ft_memcmp(s1, s2, n));
    return (0);
}
