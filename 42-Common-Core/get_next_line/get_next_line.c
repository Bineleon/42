/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:06:57 by neleon            #+#    #+#             */
/*   Updated: 2024/02/27 16:40:36 by neleon           ###   ########.fr       */
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
	if ((bytes_rd <= 0 && gnl_strlen(chars_rd) == 0) || bytes_rd == -1)
	{
		free(chars_rd);
		return (NULL);
	}
	return (chars_rd);
}


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


// // char	*gnl_read_and_store(int fd, char *chars_rd)
// // {
// // 	char	*tmp;
// // 	char	*buf;
// // 	int		bytes_rd;

// // 	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
// // 	if(!buf)
// // 		return (NULL);
// // 	bytes_rd = 1;
// // 	while (bytes_rd > 0 && !gnl_strchr(buf, '\n'))
// // 	{
// // 		bytes_rd = read(fd, buf, BUFFER_SIZE);
// // 		if (bytes_rd <= 0 && gnl_strlen(chars_rd) == 0)
// // 		{
// // 			free(chars_rd);
// // 			free(buf);
// // 			return (NULL);
// // 		}
// // 		buf[bytes_rd] = '\0';
// // 		tmp = gnl_strjoin(chars_rd, buf);
// // 		free(chars_rd);
// // 		chars_rd = tmp;
// // 	}
// // 	free(buf);
// // 	return (chars_rd);
// // }

// char	*gnl_read_and_store(int fd, char *chars_rd)
// {
// 	char	*tmp;
// 	char	*new_buf;
// 	ssize_t	bytes_read;

// 	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!tmp)
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	bytes_read = read(fd, tmp, BUFFER_SIZE);
// 	while (bytes_read > 0)
// 	{
// 		tmp[bytes_read] = '\0';
// 		new_buf = gnl_strjoin(chars_rd, tmp);
// 		free(chars_rd);
// 		chars_rd = new_buf;
// 		if (gnl_strchr(tmp, '\n'))
// 			break ;
// 		bytes_read = read(fd, tmp, BUFFER_SIZE);
// 	}
// 	free(tmp);
// 	if (bytes_read <= 0 && gnl_strlen(chars_rd) == 0)
// 	{
// 		free(chars_rd);
// 		return (NULL);
// 	}
// 	return (chars_rd);
// }

// // char	*gnl_extract_line(char **chars_rd)
// // {
// // 	char *line;
// // 	char *ptr_nl;
// // 	size_t	len_line;

// // 	ptr_nl = gnl_strchr(*chars_rd, '\n');
// // 	if(!ptr_nl)
// // 		len_line = gnl_strlen(*chars_rd);
// // 	else
// // 		len_line = ptr_nl - *chars_rd + 1;
// // 	line = gnl_substr(*chars_rd, 0, len_line);
// // 	return (line);
// // }

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
