/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:22:36 by neleon            #+#    #+#             */
/*   Updated: 2023/11/10 15:56:01 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

void ft_bzero(void *s, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);

void *ft_calloc(size_t count, size_t size)
{
    size_t total;
    void *ptr;

    total = count * size;
    ptr = (void *)malloc(total);
    if (!ptr)
        return NULL;
    ft_bzero(ptr, total);
    return (ptr);
}

int main() {
    size_t count = 5;
    size_t size = sizeof(int);

    // Test 1 : Allocation normale
    int *arr1 = (int *)ft_calloc(count, size);
    int *arr2 = (int *)calloc(count, size);

    if (ft_memcmp(arr1, arr2, count * size) != 0) {
        printf("Test 1 : FAIL\n");
    } else {
        printf("Test 1 : OK\n");
    }

    free(arr1);
    free(arr2);

    // Test 2 : Allocation avec count 0
    arr1 = (int *)ft_calloc(0, size);
    arr2 = (int *)calloc(0, size);

    if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
        printf("Test 2 : FAIL\n");
    } else {
        printf("Test 2 : OK\n");
    }

    free(arr1);
    free(arr2);

    // Test 3 : Allocation avec size 0
    arr1 = (int *)ft_calloc(count, 0);
    arr2 = (int *)calloc(count, 0);

    if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
        printf("Test 3 : FAIL\n");
    } else {
        printf("Test 3 : OK\n");
    }

    free(arr1);
    free(arr2);

    return 0;
}
