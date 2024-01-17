/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:15:43 by neleon            #+#    #+#             */
/*   Updated: 2024/01/17 15:57:40 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			full_len;

	i = 0;
	if (!s)
		return (0);
	full_len = gnl_strlen(s);
	if (start >= full_len)
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > full_len)
		len = full_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] && len-- > 0)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
char	*gnl_strchr(const char *s, int c)
{
	char	to_find;
	int		len;

	to_find = (char)c;
	len = gnl_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *join;
    size_t len_s1;
    size_t len_s2;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return (NULL);
    len_s1 = gnl_strlen(s1);
    len_s2 = gnl_strlen(s2);
    join = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if (!join)
        return (NULL);
    i = 0;
    while (i < len_s1)
        join[i] = s1[i++];
    j = 0;
    while (j < len_s2)
        join[i + j] = s2[j++];
    join[i + j] = '\0';
    return (join);
}
