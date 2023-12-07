/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:42:23 by neleon            #+#    #+#             */
/*   Updated: 2023/12/06 17:01:55 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <stdio.h>

int sumNumbers(int count, ...)
{
    va_list ap;
    int i;
    int sum;

    i = 0;
    sum = 0;
    va_start(ap, count);
    while (i < count)
    {
        sum += va_arg(ap, int);
        i++;
    }
    va_end(ap);
    return (sum);
}
int main(void)
{
    int total = sumNumbers(5, 1, 2, 3, 4, 5);
    printf("Sum is: %d\n", total);
    return (0);
}
