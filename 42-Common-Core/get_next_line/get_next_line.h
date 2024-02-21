/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:59:03 by neleon            #+#    #+#             */
/*   Updated: 2024/02/05 18:45:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// 	{
// 		/* data */
// 	};

// }					t_list;

char	*get_next_line(int fd);
char	*gnl_read_and_store(int fd, char *buf);
// void				free_gnl(char *buf);

int		gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);

#endif
