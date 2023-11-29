/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:15:28 by neleon            #+#    #+#             */
/*   Updated: 2023/11/29 17:52:14 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *ft_strtrim(char const *s1, char const *set);
// Turn in files -
// Parameters s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Return value The trimmed string.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

static int	ft_isset(char c, char const *set)
{
	return (ft_strchr(set, c) != NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	final_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	final_len = end - start;
	trimmed = (char *)malloc((final_len + 1) * (sizeof(char)));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, final_len);
	trimmed[final_len] = '\0';
	return (trimmed);
}

int	main(void)
{
	char	*s1;
	char	*set;
	char	*str;

	// Test 1: Classic trim
	s1 = "#****#Hel*lo#*##";
	set = "#*";
	str = ft_strtrim(s1, set);
	printf("Test 1: %s\n", str);
	free(str);
	// Test 2: s1 empty
	s1 = "";
	set = "#*";
	str = ft_strtrim(s1, set);
	printf("Test 2: %s\n", str);
	free(str);
	// Test 3: set empty
	s1 = "#****#Hello#*##";
	set = "";
	str = ft_strtrim(s1, set);
	printf("Test 3: %s\n", str);
	free(str);
	// Test 4: s1 NULL
	s1 = NULL;
	set = "#*";
	str = ft_strtrim(s1, set);
	printf("Test 4: %s\n", str);
	free(str);
	// Test 5: set NULL
	s1 = "#****#Hello#*##";
	set = NULL;
	str = ft_strtrim(s1, set);
	printf("Test 6: %s\n", str);
	free(str);
	// Test 6: s1 && set empty
	s1 = "";
	set = "";
	str = ft_strtrim(s1, set);
	printf("Test 6: %s\n", str);
	free(str);
	return (0);
}
