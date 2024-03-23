/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:26 by neleon            #+#    #+#             */
/*   Updated: 2024/02/29 18:23:57 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	line = NULL;
	i = 1;
	fd1 = open("./tests/test1.txt", O_RDONLY);
	fd2 = open("./tests/test2.txt", O_RDONLY);
	fd3 = open("./tests/test3.txt", O_RDONLY);
	while (i < 12)
	{
		line = get_next_line(fd1); 
		printf("Line %d : |%s|", i, line);
		free(line);

		line = get_next_line(fd2);
		printf("Line %d : |%s|", i, line);
		free(line);
		
		line = get_next_line(fd3);
		printf("Line %d : |%s|", i, line);
		free(line);
		i++;

		// line = get_next_line(-1);
		// printf("not good : |%s|", i, line);
		// free(line);
		// i++;

		// line = get_next_line(1026);
		// printf("not good : |%s|", i, line);
		// free(line);
		// i++;
		
		// line = get_next_line(42);
		// printf("not good : |%s|", line);
		// free(line);
		// // i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
