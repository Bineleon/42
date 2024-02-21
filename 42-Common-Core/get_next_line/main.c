#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *buffer = NULL; // Initialisation du buffer à NULL si la fonction s'occupe de l'allocation

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Appel de read_and_store. Notez que buffer pourrait être alloué/modifié par read_and_store
    buffer = gnl_read_and_store(fd, buffer);

    ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
        perror("Error reading file");
    // Gestion d'erreur ici

    if (buffer) {
        printf("Data read from file:\n%s\n", buffer);
        free(buffer); // Assurez-vous de libérer le buffer si read_and_store ou vous-même l'avez alloué
    } else {
        printf("No data read or allocation failed.\n");
    }

    close(fd);
    return 0;
}
