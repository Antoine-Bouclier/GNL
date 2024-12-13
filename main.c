#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test_normal.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return (1);
    }

    printf("resultat : %s", get_next_line(fd));
    printf("resultat : %s", get_next_line(fd));
    printf("resultat : %s", get_next_line(fd));
    printf("resultat : %s", get_next_line(fd));
    printf("resultat : %s", get_next_line(fd));
    printf("resultat : %s", get_next_line(fd));

    close(fd);
    return (0);
}