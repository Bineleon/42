/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:20:47 by neleon            #+#    #+#             */
/*   Updated: 2024/02/28 19:11:15 by neleon           ###   ########.fr       */
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
	char	*tmp;
	ssize_t	bytes_rd;

	buf = gnl_intit_buf();
	bytes_rd = read(fd, buf, BUFFER_SIZE);
	while (bytes_rd > 0)
	{
		buf[bytes_rd] = '\0';
		tmp = gnl_strjoin(chars_rd, buf);
		free(chars_rd);
		chars_rd = tmp;
		if (gnl_strchr(buf, '\n'))
			break ;
		bytes_rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if ((bytes_rd <= 0 && gnl_strlen(chars_rd) == 0))
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
char    *gnl_intit_buf()
{
    char *buf;

    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
    return (buf);
}

// #include "get_next_line_bonus.h"

// char	*get_next_line(int fd)
// {
// 	static char	*chars_rd[FD_MAX];
// 	char		*line;

// 	line = NULL;
// 	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
// 	if (!chars_rd[fd])
// 		return (NULL);
// 	line = gnl_extract_line(&chars_rd[fd]);
// 	if (!line)
// 	{
// 		return (NULL);
// 	}
// 	if (*line == '\0')
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
// 	return (line);
// }

// char	*gnl_read_and_store(int fd, char *chars_rd)
// {
// 	char	*buf;
// 	char	*tmp;
// 	ssize_t	bytes_rd;

// 	buf = gnl_intit_buf();
// 	tmp = NULL;
// 	bytes_rd = read(fd, buf, BUFFER_SIZE);
// 	while (bytes_rd > 0)
// 	{
// 		buf[bytes_rd] = '\0';
// 		tmp = gnl_strjoin(chars_rd, buf);
// 		free(chars_rd);
// 		chars_rd = tmp;
// 		if (gnl_strchr(buf, '\n'))
// 			break ;
// 	}
// 	free(buf);
// 	if (bytes_rd <= 0 && (gnl_strlen(chars_rd) == 0 || *chars_rd == '\0'))
// 	{
// 		free(chars_rd);
// 		return (NULL);
// 	}
// 	return (chars_rd);
// }

// char	*gnl_extract_line(char **chars_rd)
// {
// 	char	*line;
// 	char	*new_buf;
// 	char	*newline_ptr;

// 	line = NULL;
// 	new_buf = NULL;
// 	newline_ptr = gnl_strchr(*chars_rd, '\n');
// 	if (!newline_ptr)
// 	{
// 		line = gnl_strdup(*chars_rd);
// 		free(*chars_rd);
// 		*chars_rd = NULL;
// 	}
// 	else
// 	{
// 		line = gnl_substr(*chars_rd, 0, newline_ptr - *chars_rd + 1);
// 		new_buf = gnl_strdup(newline_ptr + 1);
// 		free(*chars_rd);
// 		*chars_rd = new_buf;
// 	}
// 	return (line);
// }

// char	*gnl_intit_buf(void)
// {
// 	char	*buf;

// 	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buf)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// 	return (buf);
// }




// #include "get_next_line_bonus.h"

// char	*get_next_line(int fd)
// {
// 	static char	*chars_rd[FD_MAX];
// 	char		*line;

// 	line = NULL;
// 	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
// 	if (!chars_rd[fd])
// 		return (NULL);
// 	line = gnl_extract_line(&chars_rd[fd]);
// 	if (!line)
// 	{
// 		return (NULL);
// 	}
// 	if (*line == '\0')
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
// 	return (line);
// }

// char	*gnl_read_and_store(int fd, char *chars_rd)
// {
// 	char	*buf;
// 	char	*tmp;
// 	ssize_t	bytes_rd;

// 	buf = gnl_intit_buf();
// 	bytes_rd = read(fd, buf, BUFFER_SIZE);
// 	while (bytes_rd > 0)
// 	{
// 		buf[bytes_rd] = '\0';
// 		tmp = gnl_strjoin(chars_rd, buf);
// 		free(chars_rd);
// 		chars_rd = tmp;
// 		if (gnl_strchr(buf, '\n'))
// 			break ;
// 		bytes_rd = read(fd, buf, BUFFER_SIZE);
// 		if (bytes_rd == 0)
//         	break;
// 	}
// 	free(buf);
// 	if (bytes_rd <= 0 && (gnl_strlen(chars_rd) == 0 || *chars_rd == '\0'))
// 	{
// 		free(chars_rd);
// 		return (NULL);
// 	}
// 	return (chars_rd);
// }

// char	*gnl_extract_line(char **chars_rd)
// {
// 	char	*line;
// 	char	*new_buf;
// 	char	*newline_ptr;

// 	newline_ptr = gnl_strchr(*chars_rd, '\n');
// 	if (!newline_ptr)
// 	{
// 		line = gnl_strdup(*chars_rd);
// 		free(*chars_rd);
// 		*chars_rd = NULL;
// 	}
// 	else
// 	{
// 		line = gnl_substr(*chars_rd, 0, newline_ptr - *chars_rd + 1);
// 		new_buf = gnl_strdup(newline_ptr + 1);
// 		free(*chars_rd);
// 		*chars_rd = new_buf;
// 	}
// 	return (line);
// }

// char	*gnl_intit_buf(void)
// {
// 	char	*buf;

// 	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buf)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// 	return (buf);
// }

// char	*gnl_extract_line(char *stash)
// {
// 	char	*new;
// 	size_t	len;

// 	if (gnl_strchr(stash, '\n'))
// 		len = gnl_strlen(stash) - gnl_strlen(gnl_strchr(stash, '\n')) + 1;
// 	else
// 		len = gnl_strlen(stash);
// 	new = gnl_substr(stash, 0, len);
// 	return (new);
// }

// char *update_chars_rd()
// {

// }
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

// char	*gnl_read_and_store(int fd, char *chars_rd)
// {
// 	char	*tmp;
// 	char	*buf;
// 	int		bytes_rd;

// 	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buf)
// 		return (NULL);
// 	bytes_rd = 1;
// 	while (bytes_rd > 0 && !gnl_strchr(buf, '\n'))
// 	{
// 		bytes_rd = read(fd, buf, BUFFER_SIZE);
// 		if (bytes_rd <= 0 && gnl_strlen(chars_rd) == 0)
// 		{
// 			free(chars_rd);
// 			free(buf);
// 			return (NULL);
// 		}
// 		buf[bytes_rd] = '\0';
// 		tmp = gnl_strjoin(chars_rd, buf);
// 		free(chars_rd);
// 		chars_rd = tmp;
// 	}
// 	free(buf);
// 	return (chars_rd);
// }
