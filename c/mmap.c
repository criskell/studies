#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("foo.txt", O_RDWR | O_CREAT, 0777);

    if (ftruncate(fd, 16384) < 0)
    {
        // printa uma mensagem que descreve o erro
        // e o número do erro (errno).
        perror("ftruncate");
        return 1;
    }

    // Último argumento inicializa o offset do arquivo para 0.
    char *ptr = mmap(NULL, 16384, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    ptr[0] = 'X';
    ptr[1] = '\n';
    ptr[2] = '\0';

    if (close(fd) < 0)
    {
        perror("close failed");
        return 1;
    }

    printf("RECEBA\n");
}