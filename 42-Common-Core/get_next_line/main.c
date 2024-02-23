/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:49:04 by neleon            #+#    #+#             */
/*   Updated: 2024/02/23 21:17:10 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line = NULL;
    // int i = 1;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    // line = get_next_line(fd);
    // while (line != NULL)
    // {
    //     printf("%d : ", i);
    //     printf("|%s|", line);
    //     free(line);
    //     line = get_next_line(fd);
    //     i++;
    // }

    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("|%s|", line);
        free(line);
    }

    if (close(fd) == -1)
    {
        perror("Error closing file");
        return (1);
    }

    return (0);
}

// int main(void)
// {
//     int fd;
//     char *buffer = NULL;

//     // if (argc != 2) {
//     //     printf("Usage: %s <filename>\n", argv[0]);
//     //     return 1;
//     // }

//     fd = open("test.txt", O_RDONLY);
//     printf("FD = %d\n", fd);
//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }

//     // Appel de read_and_store.
//     buffer = gnl_read_and_store(fd, buffer);
//     // buffer = get_next_line(fd);

//     // ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
//     // if (bytes_read == -1)
//     //     perror("Error reading file");
//     // // Gestion d'erreur ici

//     if (buffer) {
//         printf("Data read from file:\n|%s|\n", buffer);
//         free(buffer);
//     } else {
//         printf("No data read or allocation failed.\n");
//     }

//     close(fd);
//     return 0;
// }
