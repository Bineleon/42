/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:20:47 by neleon            #+#    #+#             */
/*   Updated: 2024/02/26 23:49:55 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*chars_rd[FD_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
	if (!chars_rd[fd])
		return (NULL);
	line = gnl_extract_line(&chars_rd[fd]);
	// if (!line)
	// {
	// 	free(line);
	// 	return (NULL);
	// }
	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);

	return (line);
}

char	*gnl_read_and_store(int fd, char *chars_rd)
{
	char	*tmp;
	char	*buf;
	int		bytes_rd;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_rd = 1;
	while (bytes_rd > 0 && !gnl_strchr(buf, '\n'))
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd <= 0 && gnl_strlen(chars_rd) == 0)
		{
			free(chars_rd);
			free(buf);
			return (NULL);
		}
		buf[bytes_rd] = '\0';
		tmp = gnl_strjoin(chars_rd, buf);
		free(chars_rd);
		chars_rd = tmp;
	}
	free(buf);
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// char	*gnl_extract_line(char *chars_rd)
// {
// 	char *line;
// 	char *ptr_nl;
// 	size_t	len_line;

// 	ptr_nl = gnl_strchr(chars_rd, '\n');
// 	if(!ptr_nl)
// 		len = gnl_strlen(chars_rd);
// 	else
// 		len = ptr_nl - chars_rd + 1;
// 	line = gnl_substr(chars_rd, 0, len);
// 	return (line);
// }