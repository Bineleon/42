/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:20:47 by neleon            #+#    #+#             */
/*   Updated: 2024/02/23 22:39:26 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *chars_rd[1024];
	char *line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
	if (!chars_rd[fd])
		return (NULL);
	line = gnl_extract_line(&chars_rd[fd]);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char *gnl_read_and_store(int fd, char *chars_rd)
{
	
}

char *gnl_extract_line(char **chars_rd)
{
	
}