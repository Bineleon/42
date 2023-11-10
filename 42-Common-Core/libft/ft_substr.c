/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:31:36 by neleon            #+#    #+#             */
/*   Updated: 2023/11/10 18:27:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Function name ft_substr
// Prototype char *ft_substr(char const *s, unsigned int start,
// size_t len);
// Turn in files -
// Parameters s: The string from which to create the substring.
// start: The start index of the substring in the
// string ’s’.
// len: The maximum length of the substring.
// Return value The substring.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			full_len;

	i = 0;
	full_len = ft_strlen(s);
      if (start >= full_len)
    {
        substr = (char *)malloc(1);
        if (!substr)
            return (NULL);
        substr[0] = '\0';
        return (substr);
    }
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
    while (s[start] && len-- > 0)
    {
        substr[i] = s[start++];
        i++;
    }
	substr[i] = '\0';
	return (substr);
}

int	main(void)
{
	char str[] = "Foo Bar Baz";
	printf("String : %s\n", str);
	printf("Substring : %s\n", ft_substr(str, 4, 3));
	return (0);
}
