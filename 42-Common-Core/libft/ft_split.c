/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:43:29 by neleon            #+#    #+#             */
/*   Updated: 2023/11/20 17:15:48 by neleon           ###   ########.fr       */
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

size_t		ft_strlen(const char *str);

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static  ft_word(char const *s, char c)
{
    char *word;
    int i;

    i = 0;
    word = (char *)malloc((ft_word_len(s, c) + 1) * sizeof(char));

    //  TO DO

}

// char **ft_split(char const *s, char c)
// {

// }

int	main(void)
{
	char	c;

	c = ' ';
	char const s[] = "Coucou me voila";
	printf("Word lenght: %d\n", ft_word_len(s, c));
}
