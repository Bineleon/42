/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:26 by neleon            #+#    #+#             */
/*   Updated: 2024/02/27 18:30:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
    // int fd1;
	// int fd2;
	// int fd3;
	int fd4;
	// int fd1done = 0;
	// int fd2done = 0;
	// int fd3done = 0;
    int fd4done = 0;

    char *line = NULL;
    int i = 1;

    // fd1 = open("test1.txt", O_RDONLY);
	// fd2 = open("test2.txt", O_RDONLY);
	// fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);


    while (i <= 20)
    {
		// if (!fd1done)
		// {
		// 	line = get_next_line(fd1);
		// 	if (line == NULL)
		// 		fd1done = 1;
		// 	printf("|%s|", line);
		// 	free(line);
		// }
		// if (!fd2done)
		// {
		// 	line = get_next_line(fd2);
		// 	if (line == NULL)
		// 		fd2done = 1;
		// 	printf("|%s|", line);
		// 	free(line);
		// }
		// if (!fd3done)
		// {
		// 	line = get_next_line(fd3);
		// 	if (line == NULL)
		// 		fd3done = 1;
		// 	printf("|%s|", line);
		// 	free(line);
		// }
        if (!fd4done)
		{
			line = get_next_line(fd4);
			if (line == NULL)
				fd4done = 1;
			printf("|%s|", line);
			free(line);
		}
		i++;
    }

	// close(fd1);
	// close(fd2);
	// close(fd3);
	close(fd4);

    return (0);
}
