/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:00:33 by neleon            #+#    #+#             */
/*   Updated: 2023/11/10 15:16:47 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

    src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
    if (dstsize <= dst_len)
        return (src_len + dstsize);
	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int main() {
    size_t  ft_result;
    size_t  real_result;
    char buff[100];

    // Test case 1: Normal concatenation
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 50);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 50);
    printf("Test 1 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 2: dstsize smaller than the combined length
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 10);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 10);
    printf("Test 2 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 3: dstsize is 0 (no space for concatenation)
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 0);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 0);
    printf("Test 3 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 4: dstsize exactly the size of dst
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 5);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 5);
    printf("Test 4 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 5: Empty src string
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, "", 50);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, "", 50);
    printf("Test 5 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 6: Empty dst string
    strcpy(buff, "");
    ft_result = ft_strlcat(buff, " World", 50);
    strcpy(buff, "");
    real_result = strlcat(buff, " World", 50);
    printf("Test 6 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 7: dstsize smaller than dst length
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 4);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 4);
    printf("Test 7 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    // Test case 8: dstsize is exactly enough for src to concatenate
    strcpy(buff, "Hello");
    ft_result = ft_strlcat(buff, " World", 11);
    strcpy(buff, "Hello");
    real_result = strlcat(buff, " World", 11);
    printf("Test 8 - ft_strlcat: %zu, strlcat: %zu, %s\n", ft_result, real_result, (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

    return 0;
}

// int main() {
//     char buffer[100];
//     char temp[100];
//     size_t ft_result, real_result;
//     int i;

//     const char *src[] = {" World", " World", " World", " World", "", " World"};
//     size_t dstsize[] = {50, 10, 0, 5, 50, 50};
//     const char *dst_initial[] = {"Hello", "Hello", "Hello", "Hello", "Hello", ""};

//     i = 0;
//     while (i < 6)
//     {
//         strcpy(buffer, dst_initial[i]);
//         strcpy(temp, buffer);

//         ft_result = ft_strlcat(buffer, src[i], dstsize[i]);
//         printf("ft_strlcat: \"%s\", Return: %zu\n", buffer, ft_result);

//         strcpy(buffer, temp);

//         real_result = strlcat(buffer, src[i], dstsize[i]);
//         printf("strlcat: \"%s\", Return: %zu\n", buffer, real_result);

//         printf("Results %s\n\n", (ft_result == real_result) ? "MATCH" : "DO NOT MATCH");

//         i++;
//     }

//     return 0;
// }
