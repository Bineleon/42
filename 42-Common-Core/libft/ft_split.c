/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:43:29 by neleon            #+#    #+#             */
/*   Updated: 2023/11/29 17:34:40 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// char **ft_split(char const *s, char c);
// Turn in files -
// Parameters s: The string to be split.
// c: The delimiter character.
// Return value The array of new strings resulting from the split.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static  char *ft_word(char const *s, char c)
{
    char *word;
    int i;

    i = 0;
    word = (char *)malloc((ft_word_len(s, c) + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (s[i] && s[i] != c)
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}
static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
        if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
            count++;
		i++;
	}
	return (count);
}
// static void	freesplit(char **split, int words)
// {
// 	int	i;

// 	i = -1;
// 	while (++i <= words)
// 	{
// 		free(split[i]);
// 		split[i] = NULL;
// 	}
// 	free(split);
// 	split = NULL;
// }

static void free_malloc(char **split, int size)
{
    int i;

    i = 0;
    if (split != NULL)
    {
        while (i < size)
        {
            free(split[i]);
            i++;
        }
        free(split);
    }
}

char **ft_split(char const *s, char c)
{
    char **words;
    int word_count;
    int i;
    int j;

    i = 0;
    j = 0;
    word_count = ft_count_words(s, c);
    words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!words)
        return (NULL);
    while (j < word_count)
    {
        while (s[i] == c)
            i++;
        words[j] = ft_word(&s[i], c);
        if (!words[j])
            free_malloc(words, j);
        i += ft_word_len(&s[i], c);
        j++;
    }
    words[word_count] = NULL;
    return (words);
}

// int	main(void)
// {
// 	char	c;
//     int i;

// 	c = ' ';
// 	char const s[] = "Coucou me voila";
//     char **split = ft_split(s, c);
//     i = 0;
//     printf("To split: %s\n", s);
//     printf("Word count: %d\nSplit: \n", ft_count_words(s, c));
//     while (i < ft_count_words(s, c))
//     {
// 	    printf("        %s\n", split[i]);
//         i++;
//     }
//     return (0);
// }
