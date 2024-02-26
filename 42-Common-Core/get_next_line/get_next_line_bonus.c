/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:20:47 by neleon            #+#    #+#             */
/*   Updated: 2024/02/26 14:38:20 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*chars_rd[1024];
	char		*line;

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

char	*gnl_read_and_store(int fd, char *chars_rd)
{
	char	*buf;
	int		bytes_read;
	char	*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0 && !gnl_strchr(buf, '\n'))
	{
        buf[bytes_read] = '\0';
        tmp = gnl_strjoin(chars_rd, buf);
        free(chars_rd);
        chars_rd = tmp;
        // if(gnl_strchr(tmp, '\n'))
        //     break;
        bytes_read = read(fd, buf, BUFFER_SIZE);
	}
    free(buf);
    if (bytes_read <= 0 && gnl_strlen(chars_rd == 0))
    {
    	free(chars_rd);
		return (NULL);
    }
    return (chars_rd);
}

char	*gnl_extract_line(char **chars_rd)
{
}
