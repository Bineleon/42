/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:26 by neleon            #+#    #+#             */
/*   Updated: 2024/02/26 23:41:01 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1;
	int fd2;
	int fd3;
	
    char *line = NULL;
    int i = 1;

    fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	
    while (i <= 6)
    {
        line = get_next_line(fd1);
        if (line == NULL)
            break;
        printf("|%s|", line);
        free(line);
		
        line = get_next_line(fd2);
        if (line == NULL)
            break;
        printf("|%s|", line);
        free(line);

        line = get_next_line(fd3);
        if (line == NULL)
            break;
        printf("|%s|", line);
        free(line);
		i++;
    }

	close(fd1);
	close(fd2);
	close(fd3);

    return (0);
}