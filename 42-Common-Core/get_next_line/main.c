/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:49:04 by neleon            #+#    #+#             */
/*   Updated: 2024/02/29 18:54:09 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int	main(void)
{
	int		fd;
	char	*line;

	line = malloc(1);
	// int i = 1;
	
	fd = open("tests/test1.txt", O_RDONLY);

	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("|%s|", line);
		i++;
	}
	// line = get_next_line(0);
	// printf("|%s|", line);
	
	close(fd);
	return (0);
}

