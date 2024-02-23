/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:06:57 by neleon            #+#    #+#             */
/*   Updated: 2024/02/23 22:22:36 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*chars_rd;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_rd = gnl_read_and_store(fd, chars_rd);
	if (!chars_rd)
		return (NULL);
	line = gnl_extract_line(&chars_rd);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*gnl_read_and_store(int fd, char *chars_rd)
{
	char	*tmp;
	char	*new_buf;
	ssize_t	bytes_read;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		tmp[bytes_read] = '\0';
		new_buf = gnl_strjoin(chars_rd, tmp);
		free(chars_rd);
		chars_rd = new_buf;
		if (gnl_strchr(tmp, '\n'))
			break ;
		bytes_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	if (bytes_read <= 0 && gnl_strlen(chars_rd) == 0)
	{
		free(chars_rd);
		return (NULL);
	}
	return (chars_rd);
}

char	*gnl_extract_line(char **chars_rd)
{
	char	*line;
	char	*new_buf;
	char	*newline_ptr;

	newline_ptr = gnl_strchr(*chars_rd, '\n');
	if (!newline_ptr)
	{
		line = gnl_strdup(*chars_rd);
		free(*chars_rd);
		*chars_rd = NULL;
	}
	else
	{
		line = gnl_substr(*chars_rd, 0, newline_ptr - *chars_rd + 1);
		new_buf = gnl_strdup(newline_ptr + 1);
		free(*chars_rd);
		*chars_rd = new_buf;
	}
	return (line);
}
