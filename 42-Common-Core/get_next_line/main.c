#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *buffer = NULL; // Initialisation du buffer à NULL si la fonction s'occupe de l'allocation

    // if (argc != 2) {
    //     printf("Usage: %s <filename>\n", argv[0]);
    //     return 1;
    // }

    fd = open("test.txt", O_RDONLY);
    printf("FD = %d\n", fd);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Appel de read_and_store. Notez que buffer pourrait être alloué/modifié par read_and_store
    buffer = gnl_read_and_store(fd, buffer);
    

    // ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    // if (bytes_read == -1)
    //     perror("Error reading file");
    // // Gestion d'erreur ici

    if (buffer) {
        printf("Data read from file:\n|%s|\n", buffer);
        free(buffer); 
    } else {
        printf("No data read or allocation failed.\n");
    }

    close(fd);
    return 0;
}
