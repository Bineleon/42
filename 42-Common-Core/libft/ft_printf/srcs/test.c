/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:38 by neleon            #+#    #+#             */
/*   Updated: 2023/12/14 15:26:25 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void) {
    int ft, libc;

    printf("Test avec une chaîne vide :\n");
    ft_printf("  ft : ");
    ft = ft_printf("\n");
    ft_printf("libc : ");
    libc = printf("\n");
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

	printf("Test avec 'ft_printf(0)' :\n");
	ft_printf("  ft : \n");
    ft = ft_printf(0);
    ft_printf("libc : \n");
    libc = printf(0);
	printf("len_ft_printf = %d et len_printf = %d\n\n", ft, libc);

    printf("Test avec pourcent '%%' :\n");
    ft_printf("  ft : ");
    ft = ft_printf("%%%%%%\n");
    ft_printf("libc : ");
    libc = printf("%%%%%%\n");
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec un caractère 'A' :\n");
    ft_printf("  ft : ");
    ft = ft_printf("%c\n", 'A');
    printf("libc : ");
    libc = printf("%c\n", 'A');
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec une chaîne de caractères :\n");
    char *str = "Test avec une chaîne \t  \tde caractères";
    ft_printf("  ft : ");
    ft = ft_printf("%s\n", str);
    ft_printf("libc : ");
    libc = printf("%s\n", str);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec une chaîne de caractères NULL :\n");
    char *strnull = NULL;
    ft_printf("  ft : ");
    ft = ft_printf("%s\n", strnull);
    ft_printf("libc : ");
    libc = printf("%s\n", strnull);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec un entier (42) :\n");
    int num = 42;
    ft_printf("  ft : ");
    ft = ft_printf("%d\n", num);
    ft_printf("libc : ");
    libc = printf("%d\n", num);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

	printf("Test avec 0 :\n");
    num = 0;
    ft_printf("  ft : ");
    ft = ft_printf("%i\n", num);
    ft_printf("libc : ");
    libc = printf("%i\n", num);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec INT_MIN et INT_MAX :\n");
    ft_printf("  ft : ");
    ft = ft_printf("%i %i\n", INT_MIN, INT_MAX);
    ft_printf("libc : ");
    libc = printf("%i %i\n", INT_MIN, INT_MAX);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

	printf("Test avec UINT_MAX :\n");
    ft_printf("  ft : ");
	unsigned int u = UINT_MAX;
	ft = ft_printf("UINT_MAX: %u\n", u);
	libc = printf("UINT_MAX: %u\n", u);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);
	
    printf("Test avec un pointeur :\n");
    int *ptr = &num;
    ft_printf("  ft : ");
    ft = ft_printf("%p\n", (void *)ptr);
    ft_printf("libc : ");
    libc = printf("%p\n", (void *)ptr);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);
 
    printf("Test avec un pointeur  NULL:\n");
    ptr = NULL;
    ft_printf("  ft : ");
    ft = ft_printf("%p\n", ptr);
    ft_printf("libc : ");
    libc = printf("%p\n", ptr);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec une valeur hexa de 42 :\n");
    ft_printf("  ft : ");
    ft = ft_printf("%x\n", 42);
    ft_printf("libc : ");
    libc = printf("%x\n", 42);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    printf("Test avec une valeur hexa en majuscule de 42 :\n");
    ft_printf("  ft : ");
    ft = ft_printf("%X\n", 42);
    ft_printf("libc : ");
    libc = printf("%X\n", 42);
    printf("Longueur Ft_printf = %d, Longueur Libc_printf = %d\n\n", ft, libc);

    return 0;
}

