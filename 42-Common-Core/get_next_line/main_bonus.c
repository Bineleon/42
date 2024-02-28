/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:26 by neleon            #+#    #+#             */
/*   Updated: 2024/02/28 19:25:46 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		fd1done;
	int		fd2done;
	int		fd3done;
	int		fd4done;
	int		i;

	fd1done = 0;
	fd2done = 0;
	fd3done = 0;
	fd4done = 0;
	line = NULL;
	i = 1;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	while (i <= 10)
	{
		if (!fd1done)
		{
			line = get_next_line(fd1);
			if (line == NULL)
				fd1done = 1;
			printf("|%s|", line);
			free(line);
		}
		if (!fd2done)
		{
			line = get_next_line(fd2);
			if (line == NULL)
				fd2done = 1;
			printf("|%s|", line);
			free(line);
		}
		if (!fd3done)
		{
			line = get_next_line(fd3);
			if (line == NULL)
				fd3done = 1;
			printf("|%s|", line);
			free(line);
		}
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
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
