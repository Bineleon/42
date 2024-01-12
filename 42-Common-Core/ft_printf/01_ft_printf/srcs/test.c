/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:38 by neleon            #+#    #+#             */
/*   Updated: 2023/12/19 14:20:32 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void) {
    int ft, org;

    printf("Test avec une chaîne vide :\n");
    printf("ft : ");
    ft = ft_printf("\n");
    printf(" libc : ");
    org = printf("\n");
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec le symbole pourcent '%%' :\n");
    printf("ft : ");
    ft = ft_printf("%%");
    printf(" libc : ");
    org = printf("%%\n");
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec un caractère 'A' :\n");
    printf("ft : ");
    ft = ft_printf("A");
    printf(" libc : ");
    org = printf("A\n");
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec une chaîne de caractères :\n");
    char *str = "Test avec une chaîne de caractères";
    printf("ft : ");
    ft = ft_printf("%s", str);
    printf(" libc : ");
    org = printf("%s\n", str);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec un entier (42) :\n");
    int num = 42;
    printf("ft : ");
    ft = ft_printf("%d", num);
    printf(" libc : ");
    org = printf("%d\n", num);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec INT_MIN et INT_MAX :\n");
    printf("ft : ");
    ft = ft_printf("%i %i", INT_MIN, INT_MAX);
    printf(" libc : ");
    org = printf("%i %i\n", INT_MIN, INT_MAX);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec un pointeur :\n");
    int *ptr = &num;
    printf("ft : ");
    ft = ft_printf("%p", (void *)ptr);
    printf(" libc : ");
    org = printf("%p\n", (void *)ptr);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec une valeur hexadécimale de 42 :\n");
    printf("ft : ");
    ft = ft_printf("%x", 42);
    printf(" libc : ");
    org = printf("%x\n", 42);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    printf("Test avec une valeur hexadécimale en majuscule de 42 :\n");
    printf("ft : ");
    ft = ft_printf("%X", 42);
    printf(" libc : ");
    org = printf("%X\n", 42);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, org);

    return 0;
}
