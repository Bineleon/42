/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minMaxAvg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:42:48 by neleon            #+#    #+#             */
/*   Updated: 2023/12/06 23:16:00 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	minMaxAvg(int *min, int *max, double *avg, int count, ...)
{
	va_list	ap;
	int		i;
    int tmp;
    int tmp2;
    double sum;

	i = 1;
	va_start(ap, count);
    tmp = va_arg(ap, int);
    *max = *min = tmp;
    sum = tmp;
	while (i < count)
	{
        tmp2 = va_arg(ap, int);
        if (tmp2 >= *max)
            *max = tmp2;
        else if (tmp2 <= *min)
            *min = tmp2;
        sum += tmp2;
        i++;
	}
    *avg = sum / count;
    va_end(ap);
}
int main() {
    int min, max;
    double avg;
    minMaxAvg(&min, &max, &avg, 5, 7, 3, 9, 2, 5);
    printf("Min: %d, Max: %d, Avg: %.2f\n", min, max, avg); // Output: Min: 2, Max: 9, Avg: 5.20
    return 0;
}
