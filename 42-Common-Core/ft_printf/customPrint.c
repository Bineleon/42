/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customPrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:54:52 by neleon            #+#    #+#             */
/*   Updated: 2023/12/08 12:49:49 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercice : Fonction customPrint
Objectif : Écrire une fonction nommée customPrint qui imite une version simplifiée de printf.
Votre fonction doit être capable de gérer les formats de chaîne de caractères %s,
les caractères %c, et les entiers %d.

Spécifications :

Le premier argument de la fonction sera une chaîne de format contenant du texte normal mélangé avec des spécificateurs de format commençant par %.
La fonction doit gérer les spécificateurs de format %s, %c, et %d uniquement.
Pour chaque spécificateur de format, la fonction doit imprimer le contenu correspondant des arguments suivants.
Prototype de la fonction :

c
Copy code
void customPrint(const char *format, ...);
Instructions :

Utilisez va_list pour gérer les arguments variables.
Parcourez la chaîne de format caractère par caractère.
Lorsque vous rencontrez un %, déterminez le spécificateur de format qui suit (s, c ou d) et imprimez l'argument correspondant.
Pour %s, imprimez la chaîne de caractères suivante.
Pour %c, imprimez le caractère suivant.
Pour %d, imprimez l'entier suivant.
N'oubliez pas d'utiliser va_end à la fin de la fonction.
Exemple d'utilisation :

c
Copy code
int main() {
    customPrint("Hello %s! You have %d new messages.\n", "Alice", 5);
    // Ceci devrait afficher "Hello Alice! You have 5 new messages."
    return 0;
}
Cet exercice vous aidera à comprendre comment printf analyse et traite les spécificateurs de format. Il constitue une excellente base pour aborder les fonctionnalités plus complexes de printf.
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_format(const char *format, va_list ap, int *count);
void ft_putchar(va_list ap, int *count);
void ft_putstr(va_list ap, int *count);
void ft_putnbr(long nb, int *count);
void ft_int_to_char(va_list ap, int *count);
void ft_uint_to_char(va_list ap, int *count);


int customPrint(const char *format, ...)
{
    va_list ap;
    int count;

    count = 0;
    va_start(ap, format);
    while(*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            ft_format(format, ap, &count);
            format++;
        }
        format++;
    }
    va_end(ap);
    return (count);
}

void ft_format(const char *format, va_list ap, int *count)
{
    if (*format == '%' && *(format + 1) == '%')
    {
        write(1, "%", 1);
        *count += 1;
    }
    else if (*format == '%' && *(format + 1) == 'c')
        ft_putchar(ap, count);
    else if (*format == '%' && *(format + 1) == 's')
        ft_putstr(ap, count);
    else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        ft_int_to_char(ap, count);
    else if (*format == '%' && *(format + 1) == 'u')
        ft_uint_to_char(ap, count);
}

void ft_putchar(va_list ap, int *count)
{
    int c;

    c = va_arg(ap, int);
    write(1, &c, sizeof(char));
    *count += 1;
}

void ft_putchar_fd(char c, int fd)
{
    write(1, &c, fd);
}

void ft_putstr(va_list ap, int *count)
{
    char *format;

    format = (char *)va_arg(ap, int *);
    while (*format)
    {
        write(1, format, sizeof(char));
        *count += 1;
        format++;
    }
}
void ft_uint_to_char(va_list ap, int *count)
{
    long nb;

    nb = va_arg(ap, int);
    ft_putnbr(nb, count);
}

void ft_int_to_char(va_list ap, int *count)
{
    long nb;

    nb = va_arg(ap, int);
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
        *count += 1;
    }
    ft_putnbr(nb, count);
}

void ft_putnbr(long nb , int *count)
{
    if (nb > 9)
        ft_putnbr(nb / 10, count);
    ft_putchar_fd(nb % 10 + '0', 1);
    *count += 1;
}

int main() {
    customPrint("Hello %s! You %% have %u new messages.\n", "Alice", 348585635);
    // Ceci devrait afficher "Hello Alice! You have 5 new messages."
    return 0;
}
