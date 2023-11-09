/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:29:08 by neleon            #+#    #+#             */
/*   Updated: 2023/11/09 17:35:48 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
            j++;
            if (!needle[j])
                return ((char *)(&haystack[i]));
		}
		i++;
	}
    return (NULL);
}

int main(void)
{
    const char hay[] = "Foo Bar Baz";
    const char need[] = "Bar";
    char *ptr;
    ptr = ft_strnstr(hay, need, 20);
    if (!ptr)
        printf("Len too short");
    else
        printf("%s\n", ptr);
    return (0);
}
